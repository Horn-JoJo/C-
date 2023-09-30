#include <iostream>
using namespace std;

//C++ 17
constexpr int Increment(int n) {
    return [n] { return n + 1; }();
}

int main() {
    //c++14
    auto lamda = [](auto a, auto b) { return a + b; };
    cout << lamda(3, 4) << ' ' << lamda(3.3, 4.4) << ' ';

    auto lamda1 = [value = 1] { return value; };//这里可以省略掉()!!!
    cout << lamda1() << endl;


    //c++17
    int y = 32;
    auto answer = [y]() constexpr {
        int x = 10;
        return y + x;
    };
    
    cout << answer() << endl;
    constexpr int n = 65;
    cout << Increment(n) << endl;
    return 0;
}

