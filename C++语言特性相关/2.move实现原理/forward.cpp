#include <iostream>
#include <utility>
using namespace std;

template <typename T>
void fun(T&& t) {
    cout << "fun rvalue bind:" << t << endl;
}

template <class T>
void fun(T& t) {
    cout << "fun lvalue bind:" << t << endl;
} 

template <typename T>
void test(T&& x) {
    fun(x);
    //因为这里形参是万能引用用来接收左值或者右值实参，
    //而实际形参是左值，因为形参已经分配了内存，
    //可以确定对应的地址 然后如果直接传入x传入到fun中时，
    //虽然数值是一样的，但是外部传入的值的类别可能发生变化了，
    //如果外部传入一个右值，而形参作为左值来接收，
    //这样传入内部函数时，变成了左值！
    fun(std::forward<T>(x));
}

int main() {
    int a = 10;
    test(10);
    //外部为右值传入 fun(x) 
    //调用传入左值10 
    //fun lvalue bind: 10 ...rvalue bind: 10...
    test(a);
    //左值传入 左值接收 fun(x) 调用传入左值10 
    //lvalue bind: 10 
    //... lvalue bind: 10...
    return 0;
}
