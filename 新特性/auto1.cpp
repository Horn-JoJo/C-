#include <iostream>
using namespace std;

auto func(int a, int b) {
    return a + b;
}

int main() {
    cout << func(22, 55) << endl;

    auto func1 = [](auto a, auto b) { return a + b; };
    cout << func1(1.99, 3.99) << endl;
    cout << func1(18, 89) << endl;
    
    auto create = [init_val = 999]() { return init_val; };
    cout << create() << endl;

    return 0;
}
