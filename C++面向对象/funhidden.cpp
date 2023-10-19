#include <iostream>
using namespace std;

//隐藏：基类某个函数和子类某个函数同名，则说明子类的实例会自动调用子类的同名函数，而隐藏掉基类的同名函数
class A {
public: 
    void fun() {
        cout << "This is A::fun()" << endl;
    }
};

class B : public A {
public:
    void fun() {
        cout << "This is B::fun()" << endl;
    }
};

int main() {
    B a;
    a.fun();
    a.A::fun();
    return 0;
}
