#include <iostream>
using namespace std;

class A {
private:
    int val;
public:
    ~A() {
        cout << "A class destructed" << endl;
    }
};

class B: public A {
private:
    int* arr;
public:
    B() {
        arr = new int[10];
    }
    ~B() {
        cout << "B class destructed" << endl;
        delete []arr;
    }
};

int main() {
    A* base = new B();
    delete base;//会内存泄漏！！！
    return 0;
}
