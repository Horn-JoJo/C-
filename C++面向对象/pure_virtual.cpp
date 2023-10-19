#include <iostream>
using namespace std;

//抽象类：含有纯虚函数的类
class interface {
public:
    virtual void fun() = 0;//纯虚函数
    void fun1() {
        cout << "This is pure virtual func" << endl;
    }
};

class A: public interface {
public:
    void funA() {
        cout << "class A is still 是  抽象类！！！" << endl;
    }
};

class B: public interface {
public:
    void fun() {
        cout << "子类B 重写 抽象类的方法fun" << endl;
    }
    void fun1() {
        cout << "子类B 覆盖 抽象类的方法fun1" << endl;
    }
};

int main() {
    //interface* base = new interface();//报错！！！因为抽象类不能示例化！！！
    
    //interface* base = new A();//也不能，因为A没有实现基类的虚函数！仍然是抽象类！！！
    
    interface* base = new B();
    base->fun();//调用子类的重写方法
    base->fun1();//调用父类的方法，因为这里需要跟指针类型看齐！！！
    //base->B::fun1();//不能找到这样的方法，因为这里用的是基类的指针！！！！
    return 0;
}
