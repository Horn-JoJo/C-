#include <iostream>
using namespace std;

/*
int test() {
    int y = 10;
    int& yref = y;//非常量左值引用绑定非常量左值
    int& xref = 10;//非常量左值引用只能绑定非常量左值！！！error!!!
    const int &ref = 10;//常量左值引用都可！！！绑定了右值
    int a = 10;
    int b = 20;
    int& ref1 = a + b;//非常量左值引用只能绑定非常量左值！！！error!!!
    
    int& aref1 = a;//非常量左值引用只能绑定非常量左值
    const int& aref2 = a;//常量左值引用都可！！！绑定了左值
    const int c = 5;//c 是常量左值！！！
    int& ref2 = c;//非常量左值引用只能绑定到非常量左值！！！error!!!这里为常量左值！！！
    const int& cref = c;//常量左值引用都可！！绑定了常量左值
    const int& ref3 = a + b;//常量左值引用都可！！绑定了右值(a+b)为表达式不能取到地址，因此为右值！！！

    return 0;
}
*/
void func(const int& c) {//参数必须是常量左值引用！！！   因此非常量左值运用只能绑定非常量左值！！！ 而常量左值引用都可以！！！

}
int main() {
    int x = 666;
    func(x);
    func(10);

    return 0;
}
