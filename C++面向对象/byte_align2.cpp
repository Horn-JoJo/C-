#include <iostream>
using namespace std;

//不含有虚继承的情况
class A {
public:
    int val;
};

class B : public A {
public:
    int b;
    void bPrint() { cout << "This is class B" << endl; }
};

/*==============================================================================================*/
//含有虚继承的情况 加入虚继承，此对象中多了一个指向虚基类表的指针，对象D和对象E都会多一个虚基类表的指针！！！vbptr
//4字节对齐
#pragma pack(4) 

class C {
public:
    int a;
};

class D : virtual public C {
public:
    int b;
    void dprint() { cout << "This is class D" << endl; }
};

class E : virtual public C {
public:
    int c;
    void eprint() { cout << "This is class E" << endl; }
};

class F : public D, public E {
public:
    int d;
    void fprint() { cout << "This is class F" << endl; }
};

int main() {
    A a;
    B b;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;

    cout << "============================================" << endl;
    C c;
    D d;
    E e;
    F f;
    cout << sizeof(c) << endl;// 4
    cout << sizeof(d) << endl;// 虚基类表指针 8 + 本类的成员变量4 + 虚基类的成员4 = 16 
    cout << sizeof(e) << endl;// 同理：16字节
    cout << sizeof(f) << endl;// D的虚基类指针8 + D的成员变量4 +(4：使得下一个为8的整数倍) + E的虚基类指针8 + E的成员变量4 + F的成员变量4 + 虚基类的成员变量4 结果=8+4+(4)+8+4+4+4+(4)
    // 如果是4字节对齐： 8 + 4 + 8 + 4 + 4 + 4

    return 0;
}
