//condition_variable notify_one
#include <iostream>
//线程库
#include <thread>
//互斥锁库：使用条件变量需要传入互斥锁
#include <mutex>
//条件变量库
#include <condition_variable>

std::mutex mtx;
std::condition_variable produce, consume;

//临界资源：多个线程共享，不能同时修改，因此需要互斥，这里实现生产者消费者同步的效果
int cargo = 0;//shared value producers and consumers

void consumer() {
    //将互斥锁传入unique_lock中，可以实现自动的加锁和解锁
    std::unique_lock<std::mutex> lck(mtx);//这里进行加锁处理，此刻其他线程不同获得这把锁，其他线程会阻塞等待互斥锁的释放
    while (cargo == 0) consume.wait(lck);//当没有货物时，消费者会阻塞线程，并且释放掉互斥锁(这里释放互斥锁的目的使得生产者获得锁，来生产cargo)
    std::cout << cargo << "\n";
    cargo = 0;//生产者消耗完了
    produce.notify_one();
}

void producer(int id) {
    //传入互斥锁加锁保护临界资源
    std::unique_lock<std::mutex> lck(mtx);
    //当货物量充足时，解锁 保证消费者可以访问到临界资源，而自己阻塞
    while (cargo != 0) produce.wait(lck);
    cargo = id;
    consume.notify_one();//这里就唤醒生产者wait操作
}

int main() {
    //创建线程对象
    std::thread consumers[10], producers[10];
    //spawn 10 consumes and 10 produces
    for (int i = 0; i < 10; i++) {
        //注册线程函数
        consumers[i] = std::thread(consumer);
        producers[i] = std::thread(producer, i + 1);
    }

    //join them back:
    //主线程等待子线程处理完毕后回收资源
    for (int i = 0; i < 10; i++) {
        producers[i].join();
        consumers[i].join();
    }

    return 0;
}
