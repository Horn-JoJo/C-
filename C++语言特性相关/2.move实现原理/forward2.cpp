#include <iostream>
using namespace std;

typedef int& lref;
typedef int&& rref;

void fun(int& t) {
    cout << "fun lvalue bind:" << t << endl;
}

void fun(int&& t) {
    cout << "fun lvalue bind:" << t << endl;
}

int main() 
{
    int a = 11;
    int& b = a;
    int&& c = 100;
    fun(static_cast<lref &&>(b));//foward
    fun(static_cast<rref &&>(c));//foward
    fun(static_cast<int &&>(a));//move
    fun(static_cast<int &&>(b));//move
    fun(static_cast<int &&>(c));//move
    return 0;
}
