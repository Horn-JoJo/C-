#include <iostream>
using namespace std;

int main() {
    int i = 10;
    const int j = 30;
    const int &x = j;
    x = 40;//const引用指向const值，但是不能修改对应的引用值
    const int &ref = i;//const引用可以指向非const变量
    double d = 3.14;
    int &ref3 = d;//error
    const int &ref2 = d;//const引用可以初始化不同类型的对象或者右值(如字符串常量值)，但非const引用不可以
}
