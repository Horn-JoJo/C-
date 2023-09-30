#include <iostream>
using namespace std;

int* fun(int t) {
    static int a = 10;
    a *= t;
    return &a;
}

int main() {
    cout << *fun(5) << endl;//50 
    cout << *fun(10) << endl;//500
    return 0;
}
