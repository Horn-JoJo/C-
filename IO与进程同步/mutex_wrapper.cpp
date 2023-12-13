#include <iostream>
#include <mutex>
using namespace std;
std::mutex mtx;

int main() {
    //构造时加锁，析构时解锁
    const std::lock_guard<std::mutex> lock(mtx);
    return 0;
}
