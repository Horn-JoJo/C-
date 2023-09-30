/*
说明：程序是在 64 位编译器下测试的
*/
#include <iostream>
using namespace std;
#define offset(TYPE,MEMBER) ((long)&((TYPE *)0)->MEMBER)
#pragma pack(push)
#pragma pack(1)
struct A
{
    short var; 
    int var1;  
    long var2;
    char var3;
    string s;
};
#pragma pack(pop)

int main()
{
    string s;
    A ex1;
    cout << offset(A, var) <<endl;
    cout << offset(A, var1) <<endl;
    cout << offset(A, var2) <<endl;
    cout << offset(A, var3) <<endl;
    cout << offset(A, s) <<endl;
    cout << sizeof(ex1) << endl;  // 47 struct
    return 0;
}
