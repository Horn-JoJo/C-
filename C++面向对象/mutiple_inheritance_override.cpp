#include <iostream>
using namespace std;

typedef void (*func) ();

class A {
public:
    virtual void fun1() { cout << "A::fun1" << endl; }
    virtual void A_fun2() { cout << "A::A_fun2" << endl; }
    virtual void A_fun3() { cout << "A::A_fun3" << endl; }
};

class B {
public:
    virtual void fun1() { cout << "B::fun1" << endl; }
    virtual void B_fun2() { cout << "B::B_fun2" << endl; }
    virtual void B_fun3() { cout << "B::B_fun3" << endl; }
};

class C {
public:
    virtual void fun1() { cout << "C::fun1" << endl; }
    virtual void C_fun2() { cout << "C::C_fun2" << endl; }
    virtual void C_fun3() { cout << "C::C_fun3" << endl; }
};

class D : public A, public B, public C {
public:
    virtual void fun1() { cout << "D::fun1" << endl; }
    virtual void D_fun2() { cout << "D::D_fun2" << endl; }
    virtual void D_fun3() { cout << "D::D_fun3" << endl; }
};

void printVtable(unsigned long* Vptr, size_t offset) {
    func fn = (func)*((unsigned long*)(*Vptr) + offset);
    fn();
}

int main() {
    A* base = new D();
    unsigned long* Vptr = (unsigned long*)base;
    //继承类：有3个虚函数指针，分别指向不同的被继承的基类的虚函数表！
    printVtable(Vptr, 0);//D::fun1() 因为这里覆盖被子类覆盖重写了，因此只有子类的对应的虚函数地址
    printVtable(Vptr, 1);//A::A_fun2
    printVtable(Vptr, 2);//A::A_fun3
    printVtable(Vptr, 3);//D::D_fun2
    printVtable(Vptr, 4);//D::D_fun3
    cout << "==================" << endl;
    Vptr++;
    printVtable(Vptr, 0);//被覆盖D::fun1()
    printVtable(Vptr, 1);//B::B_fun2
    printVtable(Vptr, 2);
    cout << "==================" << endl;
    Vptr++;
    printVtable(Vptr, 0);// D::fun1()
    printVtable(Vptr, 1);// C::C_fun2()
    printVtable(Vptr, 2);// C::C_fun3()

    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;

    return 0;
}
