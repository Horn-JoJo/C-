#include <initializer_list>
#include <iostream>
using namespace std;

int main() {
    // A 类型为 initializer_list
    auto A = {1, 2, 3, 4};
    // B 类型为 initializer_list
    auto B = {3};
    // C 类型为 int 
    auto C {4};
    return 0;
}
