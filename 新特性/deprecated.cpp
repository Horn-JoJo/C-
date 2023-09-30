#include <iostream>
using namespace std;

[[deprecated]] int f();
[[deprecated("g() is thread-unsafe. Use h() instead")]]
void g(int& x);

void h(int& x);

int main() {
    int a = f();
    g(a);
    return 0;
}

int f() {
    return 999;
}

void g(int& x) {
    x += 1;
}
