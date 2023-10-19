#include <iostream>
using namespace std;

class A {

};

int main() {
    int* p = nullptr;
    cout << sizeof(p) << endl;

    char* q = nullptr;
    cout << sizeof(q) << endl;


    int a[10];
    int* p1 = a + 1;//指针常量相加
    int* p2 = a + 4;
    bool greater = p1 > p2;//比较大小
    int offset = p2 - a;
    p2++;//自增
    p2--;//自减
    
    A* p3 = new A();

    const int c_var = 10;//const 只是告知编译器这个变量是不能修改的。
    const int* p4 = &c_var;

    return 0;
}
