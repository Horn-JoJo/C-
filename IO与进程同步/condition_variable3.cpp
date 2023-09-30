#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread() {
    std::unique_lock<std::mutex> lk(m);
    //worker 线程等待 ready
    cv.wait(lk, []{return ready;});

    //唤醒执行
    std::cout << "worker thread signals is processing data\n.";
    data += " after processing";

    //processed 设置为true, 唤醒 main 线程
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";

    //释放锁，防止再次被唤醒
    lk.unlock();
    //唤醒 main 线程
    cv.notify_one();
}

int main() {
    std::thread worker(worker_thread);
    //让 worker 线程先执行，再进行唤醒，否则可能出现ready = true 先于 worker 线程的执行
    worker.detach();

    data = "Example data";
    //设置 ready 为 true, 唤醒worker 线程
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }

    //唤醒worker线程
    cv.notify_one();

    //等待线程
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []{return processed;});
    }

    std::cout << "Back in main(), data = " << data << '\n';
    return 0;
}
