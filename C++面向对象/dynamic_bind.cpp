#include <iostream>
using namespace std;

class Base {
public:
    virtual void fun() { cout << "Base::fun()" << endl; }
};

class Derive : public Base {
public:
    void fun() {
        cout << "Derive::fun()";
    }
};

int main() {
    Base* p = new Derive();//p的静态类型是Base*, 动态类型是Derive*
    p->fun();//fun是虚函数，运行阶段进行动态绑定
    return 0;
}
