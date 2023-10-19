#include <iostream>
using namespace std;

class A {
private:
    static int var;
    const int var1;
    int var2;
    char var3;
    union {
        int a;
        short b;
        char c;
    }var4;
    //int var4; | short var4; | char var4;

public:
    A(int t): var1(t) {}
    ~A() {}
    virtual void fn() { cout << "A::fn()" << endl; }
    virtual void fn1() { cout << "A::fn1()" << endl; }
    virtual void fn2() { cout << "A::fn2()" << endl; }
};

typedef void (*func) ();
void printVtable(unsigned long* vtable, int offset) {
    unsigned long* vfptr = (unsigned long*)(*vtable);
    func fn = (func)*(vfptr + offset);//首先vptr是一个指针变量，存放的内容是虚函数表的地址！！！因此先*vptr这样就得到了虚函数表的起始地址，然后将起始地址转化为(unsinged long*)的地址值，然后pa偏移offset个字节，这样就定位了第offset的虚函数的存放的地址位置，然后在取对应的值！转化为函数指针类型！！！
    fn();
}

int main() {
    A a(666);
    A *p;
    cout << sizeof(p) << endl;
    cout << sizeof(a) << endl;//24 解释：static不算，普通函数也不算，按照顺序对齐：4 + 4 + 1 + （7填充的，保证后面变量的起始地址是8的整数倍！！！64位指针是8字节！！！） + 8
    unsigned long* vTable = (unsigned long*)&a;
    printVtable(vTable, 0);
    printVtable(vTable, 1);
    printVtable(vTable, 2);

    return 0;
}
