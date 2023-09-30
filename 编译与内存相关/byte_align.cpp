#include <iostream>
using namespace std;

class A{};
class B{
private:
    int c;//4
    double b;//4
    char a;//4
//    long long d;//8
};

class C: public A{
    virtual void fun() = 0;
};

class D: public B, public C{};

class E {
    //构造函数
    E(){}
    
    //普通成员函数
    int func0() {
        return 0;
    }

    //友元函数
    friend int func1();

    //常成员函数
    int func2() const {
        return 0;
    }

    //内联函数
    inline void func3() {
        cout << "inline func" << endl;
    }

    //静态成员函数
    static void func4() {
        cout << "static func" << endl;
    }
    
    //析构函数
    ~E(){}
};

int main() {
    //cout << sizeof(A) << endl;// 1 1
    cout << sizeof(B) << endl;// 12 12
    //cout << sizeof(C) << endl;// 4 8
    //cout << sizeof(D) << endl;// 16 24

    return 0;
}
