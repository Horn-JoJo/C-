#include <iostream>
using namespace std;

class A {
public:
    int var;
    A(int tmp) : var(tmp) {}
    void c_fun(int tmp) const {//const 成员函数 不能修改成员变量的值，不能调用非const成员函数
        var = tmp;//不能修改成员变量
        fun(tmp);//不能调用非const成员函数
    }
    void fun(int tmp) {
        var = tmp;
    }
};
int main() {
    
    return 0;
}
