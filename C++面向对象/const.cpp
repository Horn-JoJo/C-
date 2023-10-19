#include <iostream>
using namespace std;

class A {
public:
    mutable int val1;
    int val2;
    A() {
        val1 = 100;
        val2 = 200;
    }
    void fun() const {
        val1 = 200;
        val2 = 300;//这里val2没有声明为mutable可变变量，因此在const修饰的函数中是可读的！
    }
};

int main() {
    A a;
    a.fun();
    return 0;
}
