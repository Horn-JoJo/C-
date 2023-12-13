#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

//定义互斥锁
std::mutex m;
//定义条件变量
std::condition_variable cv;
//定义全局字符串
std::string data;
//定义全局bool变量 ready 和 processed
bool ready = false;
bool processed = false;

//线程函数
void worker_thread() {
    //将互斥锁传入unique_lock类中实例化，可以实现构造自动加锁，析构自动解锁
    std::unique_lock<std::mutex> lk(m);
    //worker 线程等待 是否已经ready 如果为false 则会进入解锁并进入等待
    cv.wait(lk, []{return ready;});

    //唤醒执行
    std::cout << "worker thread signals is processing data\n.";
    data += " after processing";

    //processed 设置为true, 唤醒 main 线程
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";

    //释放锁，防止再次被唤醒
    lk.unlock();//保证main线程第二个锁能被加锁从而进入wait状态
    //唤醒 main 线程的第二个wait
    cv.notify_one();
}

int main() {
    //创建线程对象
    std::thread worker(worker_thread);
    //让 worker 线程先执行，再进行唤醒，否则可能出现ready = true 先于 worker 线程的执行
    //分离主线程与子线程
    worker.detach();

    data = "Example data";
    //设置 ready 为 true, 唤醒worker 线程
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }

    //唤醒wait的worker线程 
    cv.notify_one();

    //等待线程
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []{return processed;});
    }

    std::cout << "Back in main(), data = " << data << '\n';
    return 0;
}
