/*
 decltype 声明类型
 */
#include <iostream>
using namespace std;

using nullptr_t = decltype(nullptr);
typedef decltype(nullptr) nullptr_t;

int main() {
    const int&& foo();
    const int bar();
    int i;
    struct A { double x; };
    const A* a = new A();
    decltype(foo()) x1 = bar();//类型为const int&&
    decltype(bar()) x2;//类型为int
    decltype(i) x3;//类型为int
    decltype(a->x) x4;//类型为double
    decltype(a->x) x5;//类型为const double&
    

    
    return 0;
}
