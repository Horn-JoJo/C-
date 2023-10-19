#include <iostream>
#include <new>
using namespace std;

class A {
private:
    void *operator new(size_t) {}//设为私有 注意函数的参数和返回值都是固定的！！！
    void operator delete(void* ptr) {}//delete成对出现设为私有！！！
public:
    A() {}
    ~A() {}
};

int main() {


    return 0;
}
