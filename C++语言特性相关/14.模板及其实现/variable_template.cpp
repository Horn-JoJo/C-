#include <iostream>
using namespace std;

template <typename T>
constexpr T pi = T{3.141592653589793238462643383L};

template <class T>
class A {
public:
    static T val;
};
A<int> a;
A<string> b;

int main() {
    cout << pi<double> << endl;
    cout << pi<float> << endl;

    return 0;
}
