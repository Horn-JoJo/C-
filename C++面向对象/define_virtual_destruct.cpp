#include <iostream>
using namespace std;

class A {
private:
    int val;
public:
    virtual ~A() {
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
    virtual ~B() {//这里可加可不加
        cout << "B class destructed" << endl;
        delete []arr;
    }
};

int main() {
    A* base = new B();
    delete base;//加了virtual修饰后，使用基类指针指向子类对象时，使用delete 删除基类指针所指向的内存时，会首先调用子类的析构函数，然后再调用基类的析构函数
    return 0;
}
