#include <iostream>
using namespace std;

class Uncopyable {
public:
    Uncopyable() {}
    ~Uncopyable() {}
private:
    int a;
    friend class A;
    Uncopyable(const Uncopyable&);//拷贝构造函数
    Uncopyable& operator=(const Uncopyable&);//赋值构造函数
};

class Uncopyable1 {
public:
    Uncopyable1() {}
    ~Uncopyable1() {}
    Uncopyable1(const Uncopyable1&) = delete;//禁用拷贝构造函数
    Uncopyable1& operator=(const Uncopyable1&) = delete;//禁用重载运算符
};

class A : private Uncopyable {
public:
    void print(Uncopyable A) { A.a = 666; cout << A.a << endl; }
};
class B : Uncopyable1 {

};
int main() {
    A a1;
    A a2;
    a1.print(Uncopyable());
    a1 = a2;//报错！！！
    //A b = a;
    //b = a;
    B b;
    //B b = B();
    B c;
    //c = b;
    return 0;
}
