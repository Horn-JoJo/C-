# include <iostream>
using namespace std;
//当对象的值可能在程序的控制或检车之外被改变时，应该将对象声明为volatile，告知编译器不应对这样的对象进行优化。

int main() {
    int i = 10;
    i = 0x10;
    i = 0x11;
    i = 0x22;

    return 0;
}
