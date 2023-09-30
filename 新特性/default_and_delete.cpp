#include <iostream>
using namespace std;

class A {
public:
    A() = defalut;//表示使用系统默认的构造函数
    ~A() = defalut;//表示使用系统默认的析构函数
    A(const A &) = delete;//表示类的对象禁止拷贝构造
    A &operator=(const A &) = delete;//表示类的对象禁止赋值构造 
};

int main() {
    A ex1;
    A ex2 = ex1;//拷贝构造报错
    A ex3;
    ex3 = ex1;//赋值构造报错

    return 0;
}
