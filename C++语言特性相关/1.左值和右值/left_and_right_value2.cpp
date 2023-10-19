#include <iostream>
using namespace std;

int global = 666;

void processValue(int&& i) {
    cout << "rvalue i = " << i << endl;
}

void processValue(int& i) {//非常量左值引用只能绑定非常量左值
    cout << "lvalue i = " << i << endl;
}

int getValue() {
    return 555;
}

int& getGlobal() {
    return global;
}

void test(int&& x) {

}

int main() {
    int a = 0;
    int b = 1;
    int& ref = a;//非常量左值引用只能绑定非常量左值
    int&& ref1 = 666;//右值引用只能绑定右值！！！
    int&& ref2 = getValue();//右值引用只能绑定右值！！！这里右值临时变量！！！不能取到地址！！
    processValue(a);//左值                                   lvalue i = 0
    processValue(getValue());//实参为右值                    rvalue i = 555
    processValue(1);//实参为右值                             rvalue i = 1
    processValue(getGlobal());//实参为引用，能找到地址，     lvalue i = 666
    processValue(a+b);//实参为右值，                         rvalue i = 1 
    
    //test(a);右值引用只能绑定到右值！！！
    test(666);
    return 0;
}
