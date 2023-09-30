#include <iostream>
using namespace std;

class A {
public:
    int var;
    A(int tmp) {
        var = tmp;
    }
    void fun();
};

inline void A::fun() {
    cout << var << endl;
}

int main() {
    A a(111);
    a.fun();
    return 0;
}
