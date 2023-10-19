#include <iostream>
using namespace std;

// 需要思考每个类的虚函数表的分布情况是咋样分配的！！！
class A {
private:
    int a1;
    int a2;
public:
    virtual void display() { cout << "A::display()" << endl; }
    virtual void clone() { cout << "A::clone()" << endl; }
};

class B : public A {
private:
    int b;
public:
    virtual void display() override { cout << "B::display()" << endl; } 
    virtual void init() { cout << "B::init()" << endl; }
};

class C : public B {
private:
    int c;
public:
    virtual void display() override { cout << "C::display()" << endl; }
    virtual void execute() { cout << "C::execute()" << endl; }
    virtual void init() override { cout << "C::init()" << endl; }
};

int main() {
    A* p1 = new B();
    A* p2 = new C();
    p1->display();
    p2->display();

    return 0;
}
