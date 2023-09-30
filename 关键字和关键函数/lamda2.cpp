#include <iostream>
using namespace std;

int main() {
    size_t t = 9;
    auto f = [t]() mutable {
        t++;
        return t;
    };
    
    cout << f() << endl;//10
    cout << f() << endl;//11
    cout << t << endl;//9
    
    return 0;
}
