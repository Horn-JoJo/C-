#include <iostream>
using namespace std;

template <typename T>
T add_fun(const T& t1, const T& t2) {
    return t1 + t2;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << add_fun<int>(a, b);//显示调用
    
    double c, d;
    cin >> c >> d;
    cout << add_fun(c, d);//隐式调用

    return 0;
}
