#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>

class ThreadSafeCounter {
public:
    ThreadSafeCounter() = default;//默认构造函数

    //多个线程同时读取counter计数
    unsigned int get() const {
        std::shared_lock lock(mutex_);
        return value_;
    }

    //只有一个线程可以修改counter计数
    void increment() {
        std::unique_lock lock(mutex_);
        value_++;
    }

    //只有一个线程可以修改counter计数
    void reset() {
        std::unique_lock lock(mutex_);
        value_ = 0;
    }
private:
    //注意这里的mutable使得被修饰变量能够在const的语境下被修改
    mutable std::shared_mutex mutex_;
    unsigned int value_ = 0;
};

int main() {
    ThreadSafeCounter counter;

    //线程函数
    auto increment_and_print = [&counter]() {
        for (int i = 0; i < 3; i++) {
            counter.increment();
            std::cout << std::this_thread::get_id() << ' ' << counter.get() << std::endl;
            //注意，在真实情况下输出cout也需要进行同步处理，（被另外的锁控制），这里省略
        }
    };

    std::thread thread1(increment_and_print);
    std::thread thread2(increment_and_print);
    
    thread1.join();
    thread2.join();
}
/*
139677317637888 2
139677317637888 3
139677309245184 4
139677309245184 5
139677309245184 6
139677317637888 6
*/
