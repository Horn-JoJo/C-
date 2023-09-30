#include <iostream>
using namespace std;

inline int add(int a, int b) {
    return a + b;
}

int main() {
    cout << add(12, 34) << endl;
    return 0;
}
