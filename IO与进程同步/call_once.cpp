#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::once_flag flag1, flag2;
/*
template <class Callable, class... Args>
void call_once(std::once_flag& flag, Callable&& f, Args&&... args);
*/ 

void simple_do_once() {
    std::cout << "is running simple_do_once" << endl;
    //这个
    std::call_once(flag1, []() { std::cout << "simple example: called once\n"; });
    cout << "hhhhhh " << endl;
}

int main() {
    //所有的线程都会执行simple_do_once的函数，只是call_once这个只会被某一个线程函数执行一次！！！其他线程函数就会忽略掉这一行！！！！
    std::thread st1(simple_do_once);
    std::thread st2(simple_do_once);
    std::thread st3(simple_do_once);
    std::thread st4(simple_do_once);
    st1.join();
    st2.join();
    st3.join();
    st4.join();

    return 0;
}
