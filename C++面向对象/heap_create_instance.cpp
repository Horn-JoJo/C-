#include <iostream>
using namespace std;

//方法1：能实现只能在堆构造，但是存在一系列问题
class A {
public:
    A() {}
    void destrory() {
        delete this;
    }
private:
    ~A() {}
};

//方法2：将构造函数和私有函数设为保护，既保证了该类必须在堆上创建实例，然后也能实现正常被继承
//同时这也是单例模式的实现方式。
class B {
protected:
    B() {}
    ~B() {}
public:
    static B* getInstance() {
        return new B();
    }
    void delInstance() {
        delete this;
    }
};

int main() {
    A* a = new A();
    a->destrory();

    B* b = B::getInstance();
    b->delInstance();
    
    return 0;
}
