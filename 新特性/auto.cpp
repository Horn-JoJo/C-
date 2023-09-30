#include <iostream>
using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;
    
    auto a = val1 + val2;//根据val1 和 val2 相加的结果推断出 var 的类型
    auto ret = [](double x) { return x * x; };//根据函数返回值推导出ret 的类型
    auto al = { 10, 11, 12 };//类型是std::initializer_list<int>
    

    const int v1 = 101;
    auto v2 = v1;//可赋值, auto 不能自动推导出const或者volatile
    v2 = 102;
    int a1 = 100;
    int& b = a1;
    auto c = b;//c类型为int, 脱去初始表达式的&


    int d[9];
    auto j = d;//此时j指针为 int* 类型，而不是 int(*)[9]类
    std::cout << typeid(j).name() << " " << sizeof(j) << " " << sizeof(a) << std::endl;

    return 0;
}

