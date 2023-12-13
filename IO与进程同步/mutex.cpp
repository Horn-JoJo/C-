#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

std::mutex mtx;

void print_lock(int n, char a) {
    mtx.lock();
    for (int i = 0; i < n; i++) cout << a;
    cout << endl;
    mtx.unlock();
}

int main() {
    std::thread th1(print_lock, 30, '*');
    std::thread th2(print_lock, 20, '$');
    
    th1.join();
    th2.join();

    return 0;
}
