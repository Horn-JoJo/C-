#include <iostream>
using namespace std;

class A {
public:
    int var1;
    int var2;
    A() {
        var1 = 10;
        var2 = 20;
    }
    virtual void fun() = 0;//纯虚函数
};


class B {
private:
    B() {}
};

class C {
public:
    C() = delete;
    ~C() = delete;
};

int main() {
    A a;
    B b;
    C c;
    return 0;
}
