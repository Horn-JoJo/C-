#include <iostream>
using namespace std;

class A {
public:
    static int s_var;
    int var;
    void fun1(int i = s_var);//正确，静态成员变量可以作为成员函数的参数
    //void fun2(int i = var);//error: invalid use of non-static data 'A::var'

};

int main() {

    return 0;
}
