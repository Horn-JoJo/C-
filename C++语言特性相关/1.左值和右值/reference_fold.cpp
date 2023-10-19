#include <cstdlib>
#include <iostream>
using namespace std;

typedef int& lref;
typedef int&& rref;

void fun(int&& tmp) {
    cout << "fun rvalue bind: " << tmp << endl; 
}

void fun(int& tmp) {
    cout << "fun lvalue bind: " << tmp << endl;
}

int main() {
    int n = 10;
    fun((lref&)n);//左值
    fun((lref&&)n);//左值
    fun((rref&)n);//左值
    fun((rref&&)n);//右值

    return 0;
}
