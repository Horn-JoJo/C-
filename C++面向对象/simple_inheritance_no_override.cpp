#include <iostream>
using namespace std;

typedef void (*func) (void);

class A {
public:
    virtual void fun1() { cout << "A::fun1" << endl; }
    virtual void fun2() { cout << "A::fun2" << endl; }
    virtual void fun3() { cout << "A::fun3" << endl; }
};

class B : public A {
public:
    virtual void fun4() { cout << "B::fun4" << endl; }
    virtual void fun5() { cout << "B::fun5" << endl; }
    virtual void fun6() { cout << "B::fun6" << endl; }
};

void printVtable(unsigned long* vPtr, size_t offset) {
    func fn = (func)*((unsigned long*)(*vPtr) + offset);
    fn();
}

int main() {
    A* base = new B();
    base->fun1();

    cout << "=============================" << endl;
    unsigned long* vPtr = (unsigned long*)base;//base本来就是指向某个对象的地址，因此不用&
    printVtable(vPtr, 0);//A::fun1
    printVtable(vPtr, 1);//A::fun2
    printVtable(vPtr, 2);//A::fun3
    printVtable(vPtr, 3);//B::fun4
    printVtable(vPtr, 4);//B::fun5
    printVtable(vPtr, 5);//B::fun6

    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;

    return 0;
}
