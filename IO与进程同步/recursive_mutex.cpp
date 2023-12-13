#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::recursive_mutex mtx;

void fun1() {
    mtx.lock();
    cout << "fun1的临界资源" << endl;
    mtx.unlock();
}

void fun2() {
    mtx.lock();
    fun1();
    cout << "fun2的临界资源" << endl;
    mtx.unlock();
}

int main() {
    thread th1(fun1);
    thread th2(fun2);

    th1.join();
    th2.join();

    return 0;
}
