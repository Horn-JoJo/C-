#include <iostream>
using namespace std;

class A {
private:
    friend class B;
    int val;
public:
    A() : val(10) {}
    A(int t) : val(t) {}
    void fun() { cout << "fun()" << val << endl; }
};

class B {
private:
    A ex;
public:
    B() {}
    void fun() { 
        cout << "fun():" << ex.val << endl;//访问类A中的私有成员
    }
};

int main() {
    B ex;
    ex.fun();// fun():10

    return 0;
}
