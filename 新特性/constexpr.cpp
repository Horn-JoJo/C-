#include <iostream>
using namespace std;

constexpr int g() { return 5; }
constexpr double PI = 3.1415926525;

int main() {
    int f[g() + 5];    
    cout << sizeof (f) / sizeof (f[0]) << endl; 
    return 0;
}
