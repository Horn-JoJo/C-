#include <iostream>
using namespace std;

void fun(int& tmp) {
    cout << "fun lvalue bind: " << tmp << endl;
} 

void fun(int&& tmp) {
    cout << "fun rvalue bind: " << tmp << endl;
}

void fun1(int& tmp) {
    cout << "fun1 lvalue bind: " << tmp << endl;
}

int main() {
    int var = 11;
    fun(12);//右值引用 
    fun(var);//左值引用
    fun(move(var));//使用move右值引用
    fun(static_cast<int&&>(var));//使用static_cast转化为右值引用
    fun((int&&)var);//使用c风格强转为右值引用
    fun(forward<int&&>(var));//使用std::forward<T&& 转为右值引用
    //fun1(12);//error

    return 0;
}
