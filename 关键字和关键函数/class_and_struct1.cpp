#include <iostream>
using namespace std;

class A {
public:
    void funA() {
        cout << "class A" << endl;
    }
};

struct B: A {//公有继承
public:
    void funB() {
        cout << "class B" << endl;
    }
};

class C: B {//私有继承 因此无法访问到struct B中的funB

};

int main() {
    A ex1;
    ex1.funA();//class A

    B ex2;
    ex2.funA();//class A 
    ex2.funB();//class B 

    C ex3;
    ex3.funB();//error  ‘B’ is not an accessible base of ‘C’

    return 0;
}
