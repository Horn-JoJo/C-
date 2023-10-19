# include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

typedef int (*fun_p)(int, int);

class A {
public:
    int var1, var2;
    static int x;
    static int get() {
        return 100;
    }

    int add() {
        return var1 + var2;
    }
};


int main() {
    fun_p fn = add;
    cout << fn(1, 6) << endl;//7 
    
    A ex;
    ex.var1 = 3;
    ex.var2 = 4;
    int* p = &ex.var1;//指向对象成员变量的指针
    cout << *p << endl;//3

    int (A::*fn_p) ();//定义一个类的非静态函数指针变量
    int (*fn_q) ();//定义一个类的静态函数指针变量
    fn_p = &A::add;//非静态函数指针变量 初始化需要指定哪个类的函数 并且需要取地址
    fn_q = A::get;//指向对象静态成员函数的指针 fn_q 这个跟普通的函数指针没有区别！！！
    cout << (ex.*fn_p)() << endl;//调用类的非静态成员函数时，需要指定实例然后取*操作得到函数地址，然后再调用
    cout << (*fn_q)() << endl;

    return 0;
}
