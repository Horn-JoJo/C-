#include <iostream>
using namespace std;

template <class T>
constexpr T Pi = T(3.1415926535897632385L);

int main() {
    cout << Pi<int> << endl;//3
    cout << Pi<double> << endl;//3.14159

    return 0;
}
