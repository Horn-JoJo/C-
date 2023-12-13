#include <iostream>
#include <future>
#include <chrono>
#include <functional>
#include <thread>

using T = std::function<int(int, int, int&)>;
//typedef std::function<int(int, int, int&) T;

void fun1(std::promise<int>& p) {
    std::cout << "thread fun1 is running..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    p.set_value(999);
}

void fun2(std::future<int>& f) {
    std::cout << "thread fun2 is running..." << std::endl;
    std::cout << "waitting for f.get()" << std::endl;
    //这里会先被执行到，接下来会阻塞在get这里
    //因为fun1在5s过后才会设置值，因此这里会等待！！！
    auto v = f.get();
    std::cout << "f.get() = " << v << std::endl;
}

int main() {
    std::promise<int> p;//定义一个用来保存int的变量
    std::future<int> f = p.get_future();//绑定p和f p.set_value() => f.get()
    
    std::thread t1(fun1, std::ref(p));
    std::thread t2(fun2, std::ref(f));
    
    t1.join();
    t2.join();
    //主线程等待子线程运行完才继续执行主线程逻辑

    return 0;
}
