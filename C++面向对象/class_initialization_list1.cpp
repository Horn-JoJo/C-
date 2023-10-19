#include <iostream>
using namespace std;

class A {
public:
    int val;
    A() { cout << "A()" << endl; }
    A(int t) { cout << "A(int t)" << endl; }
};

class B {
    A a;
public:
    B() {
        a = A(666);
        cout << "B()" << endl;
    }
};

class C {
    A a;
public:
    C() : a(999) { 
        cout << "C()" << endl;
    }
};

int main() {
    B b;// A() A(int t) B()
    cout << "===================" << endl;
    C c;//A(int t) C()
    return 0;
}
