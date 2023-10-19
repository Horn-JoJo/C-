#include <iostream>
#include <memory>
using namespace std;


typedef void (*func)(void);//定义函数指针！！！

class A {
public:
    void f() { cout << "A::f" << endl; }
    void g() { cout << "A::g" << endl; }
    void h() { cout << "A::h" << endl; }
};

class Base {
public:
    virtual void f() { cout << "Base::f" << endl; }
    virtual void g() { cout << "Base::g" << endl; }
    virtual void h() { cout << "Base::h" << endl; }
};

class Derive: public Base {
    void f() { cout << "Derive::f" << endl; }
    void g() { cout << "Derive::g" << endl; }
    void h() { cout << "Derive::h" << endl; }
};

int main() {
    //定义基类对象
    Base base;
    //定义子类对象
    Derive derive;

    //获取vptr的地址，运行在gcc x64环境下，所以将指针按unsigned long * 大小处理
    //另外基于C++的编译器应该是保证虚函数表的指针存在于对象实例中最前面的位置
    unsigned long* vPtr = (unsigned long*)(&base);
    
    //获取vTable 首个函数的地址
    func vtable_f = (func)*(unsigned long*)(*vPtr);

    //获取vTable第二个函数的地址
    func vtable_g = (func)*((unsigned long*)(*vPtr) + 1);
    func vtable_h = (func)*((unsigned long*)(*vPtr) + 2);

    vtable_f();//Base::f
    vtable_g();//Base::g
    vtable_h();//Base::h

    //获取子类的首个函数的地址
    vPtr = (unsigned long*)(&derive);
    vtable_f = (func)*(unsigned long*)(*vPtr);
    vtable_f();//derive::f 
    vtable_g = (func)*((unsigned long*)(*vPtr) + 1);
    vtable_h = (func)*((unsigned long*)(*vPtr) + 2);
    vtable_g();
    vtable_h();

    cout << sizeof(A) << endl;
    cout << sizeof(base) << endl;
    cout << sizeof(derive) << endl;

    return 0;
}
