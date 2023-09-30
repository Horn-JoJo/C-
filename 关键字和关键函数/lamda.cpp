#include <iostream>
using namespace std;

int main() {
    int a = 10;
    auto f = [&a](int x) -> int {
        a = 20;
        return a + x;
    };
    
    //10
    cout << a << endl;
    //30
    cout << f(10) << endl;
    //20
    cout << a << endl;

    return 0;
}
