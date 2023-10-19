#include <iostream>
using namespace std;

// 禁止构造函数 : 构造函数实现体增加=delete修饰符，可以达到虽然声明了构造函数但是禁止使用的目的。

class A {
private:
    int var1;
    int var2;
public:
    A() {
        var1 = 10;
        var2 = 20;
    }
    A(int t1, int t2) = delete;
};

int main() {
    A a;
    A b(100, 200);//调用这里会报错，因为该构造函数是delete的

    return 0;
}
