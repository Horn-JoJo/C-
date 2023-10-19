#include <iostream>
using namespace std;

template <typename T>
T add_fun(const T& t1, const T& t2) {
    return t1 + t2;
}

int main() {
    int var1, var2;
    cin >> var1 >> var2;
    cout << add_fun(var1, var2) << endl;
    
    double var3, var4;
    cin >> var3 >> var4;
    cout << add_fun(var3, var4) << endl;
    return 0;
}
