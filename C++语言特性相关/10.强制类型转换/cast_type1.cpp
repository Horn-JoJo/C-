#include <iostream>
#include <cstring>
using namespace std;

class Base {
public:
    virtual void fun() {
        cout << "Base::fun()" << endl;
    }
};

class Derive: public Base {
public:
    virtual void fun() {
        cout << "Derive::fun()" << endl;
    }
};

int main() {
    Base* p1 = new Derive();//基类指针指向继承类对象
    Base* p2 = new Base();//基类指针指向基类对象
    Derive* p3 = new Derive();//子类指针指向子类对象

    //转换成功
    p3 = dynamic_cast<Derive*>(p1);//因为基类指针指向了子类对象，因此可以向下转型成子类指针！
    if (p3 == NULL) {
        cout << "NULL" << endl;
    } else {
        cout << "NOT NULL" << endl;//输出
    }

    //转换失败
    p3 = dynamic_cast<Derive*>(p2);//因为基类指针指向了基类对象，因此不能向下转型成子类指针！
    if (p3 == NULL) {
        cout << "NULL" << endl;//输出
    } else {
        cout << "NOT NULL" << endl;
    }

    return 0;
}
