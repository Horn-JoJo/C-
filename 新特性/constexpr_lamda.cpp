#include <iostream>
using namespace std;

int main() {
    constexpr auto lamda = [](int n) { return n * n; };//编译器进行计算！！！
    static_assert(lamda(3) == 9, "a");

    return 0;
}
