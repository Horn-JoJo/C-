#include <iostream>
using namespace std;

class A {
private:
    int val;
public:
    A() {
        cout << "A()" << endl;
    }
    A(int t) {
        val = t;
        cout << "A(int " << val << ")" << endl;
    }
};

class B {
private:
    int val;
public:
    B() : val(111) { cout << "val = " << val << endl; }//成员初始化列表方式 
};

int main() {
    A a;
    B b;

    return 0;
}
