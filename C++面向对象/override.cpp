#include <iostream>
using namespace std;

//函数覆盖|重写：当一个基类指针，指向子类对象时，调用用virtual修饰的虚函数时，会调用子类的重写的同名函数

class Base {
public:
    virtual void myfun() {
        cout << "This is Base virtual myfun" << endl;
    }
};

class B : public Base {
public:
    //这里可以不用virtual关键字声明，因为无需让继承该类的子类来重写该方法！！！
    void myfun() {
        cout << "This is B virtual myfun" << endl;
    }
};

int main() {
    Base* p = new B();
    p->myfun();

    return 0;
}
