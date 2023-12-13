#include <iostream>
#include <future>
#include <thread>
using namespace std;

int main() {
    //future from async 
    //使用std::async创建匿名函数的线程函数
    std::future<int> f1 = std::async(std::launch::async, [] { return 8; });

    //future from a promise
    std::promise<int> p;//确定要在一个线程中设置的值类型为int类型 这个用于传入一个线程，并且在线程里设置值
    std::future<int> f2 = p.get_future();//将future对象绑定！！！
    //这个用于另外一个线程，用于获取与该对应绑定的int类型值
    
    //这个将p传入匿名函数创建的线程中，并设置值为9
    std::thread([&p] { p.set_value_at_thread_exit(9); }).detach();

    std::cout << "Waiting..." << std::flush;
    //等待f1和f2两个异步线程执行完
    f1.wait();
    f2.wait();
    //分别打印每个异步线程返回的结果
    std::cout << "Done!\nResults are: " << f1.get() << ' ' << f2.get() << endl;
    
    return 0;
}
