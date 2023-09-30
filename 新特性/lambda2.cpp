#include <iostream>
using namespace std;

int main() { 
    size_t t = 9; 
    auto f = [t]() mutable {
        t++; return t;
    };
    cout << t << endl;//9 
    cout << f() << endl;//10 
    cout << t << endl;//9 
    
    t = 100; 
    cout << f() << endl;//11 不会重新捕获t!!! 继续使用第一次内部t继续计算!!!
    cout << "t: " << t << endl;//打印的是外部修改后的值 
    
    return 0;
}

