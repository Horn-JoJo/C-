#include <iostream>
using namespace std;

int main() {
#if D1
    int x = 0;
    int* q = &x;
    const int *p = &x;
    //*p = 10;//error const 修饰的是*, 所有不能修改内容，但是可以修改指针指向
    p = q;
#endif
#if D2 
    int a = 8;
    int* const p = &a;//指针为常量，不能修改指针指向，但是可以修改内容
    *p = 9;
    int b = 7;
    p = &b;
#endif
    int a = 8;
    const int* const p = &a;

    return 0;
}
