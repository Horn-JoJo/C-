#include <iostream>
using namespace std;

//模板声明可以是class 也可以是typename
template <class T>
T Max(T& a, int& b) {
    return a > b ? a : b;
}

//这里可以不用T1, 但是至少需要用一个，即函数返回值类型和参数列表类型有一个是声明的类型！！！
template <typename T, typename T1>
int Min(T& a, T1 b) {
    return a < b ? a : b;
}

int main() {
    int a = 399;
    int b = 3888;
    char c = 'a';
    cout << Max(a, b) << endl;//编译器自动推导
    cout << Min<int, int>(a, c) << endl;//显示调用
    return 0;
}
