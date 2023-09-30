#include <iostream>
using namespace std;

struct A {
    char a[10];//向相邻较大的数据类型int的整数倍对齐 10->12
    int b[4];//16字节
    char c; //首选画出前面的数据的内存分布情况，然后保证数据完整性的情况下进行填充字节，使得前后数据类型一次读取数据的完整性。
    char *p;//8字节
};

struct B {
    char a;
    short b;
    bool c;
};

struct C {
    bool a;//1->4
    int b;//4
    bool c;//1->4 32位 1->8
    long long d;//8
};
int main() {
#if 0
    cout << sizeof(A) << endl;//64: 40字节  32：36字节

    void *p1, *p2, *p3, *p4;
    struct A t;
    p1 = &t.a;
    p2 = &t.b;
    p3 = &t.c;
    p4 = &t.p;
        
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;
#else
//    cout << sizeof (B) << endl;
    struct C t;
    void *p1 = &t.a;
    void *p2 = &t.b;
    void *p3 = &t.c;
    void *p4 = &t.d;
    
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;
    
#endif
    return 0;
}
