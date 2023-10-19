#include <iostream>
using namespace std;

void fun1(int t) {//值传递
    cout << &t << endl;
}

void fun2(int* t) {//指针传递
    cout << t << endl;
}

void fun3(int& t) {//引用传递
    cout << &t << endl;
}

int main() {
    int var = 5;
    cout << "var 在主函数中的地址:" << &var << endl;
    
    cout << "var 值传递时的地址:";
    fun1(var);
    
    cout << "var 指针传递时的地址:";
    fun2(&var);

    cout << "var 引用传递时的地址:";
    fun3(var);

    return 0;
}
