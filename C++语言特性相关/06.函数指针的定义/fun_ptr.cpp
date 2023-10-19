#include <iostream>
using namespace std;

int fun1(int t1, int t2) {
    return t1 * t2;
}

int fun2(int t1, int t2) {
    return t1 / t2;//bug: t2 != 0
}

int main() {
    int (*fun)(int x, int y);
    fun = fun1;
    fun = &fun1;//以上两种均可
    cout << fun(15, 5) << endl;
    fun = fun2;
    //cout << sizeof(fun1) << endl;//error
    //函数名可以无限解引用和取地址，得到的都是函数指针
    cout << sizeof(&fun1) << endl;

    return 0;
}
