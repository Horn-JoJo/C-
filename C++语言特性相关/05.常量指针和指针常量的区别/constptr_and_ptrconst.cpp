#include <iostream>
using namespace std;

int main() {
    const int c_var = 8;
    const int c_var1 = 777;
    //常量指针
    const int* p = &c_var;
    //*p = 6;//error
    cout << *p << endl;
    int c = 9;
    p = &c;
    cout << *p << endl;


    //指针常量
    int b = 999;
    int* const p1 = &c;
    //p1 = &b;
    *p1 = 666;
    cout << *p1 << endl;
    

    //常量指针常量
    int const * const p2 = &c_var;
    //p2 = &c_var1;error
    //*p2 = 888;error
    return 0;
}
