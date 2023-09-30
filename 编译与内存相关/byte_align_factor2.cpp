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
    cout << alignof(A) <<endl;
    return 0;
}
