#include <cstdio>
#include <iostream>
using namespace std;

template <typename T>
void print_fun(const T& t) {
    cout << t << endl;//最后一个元素
}

template <typename T, typename... Args>
void print_fun(const T& t, const Args&... args) {
    cout << t << "->";
    print_fun(args...);
}

int main() {
    print_fun("dog");
    print_fun("Hello", "world", "!");
    return 0;
}
