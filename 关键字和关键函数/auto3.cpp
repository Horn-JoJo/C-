#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

/*
 
左值：可位于赋值号(=)左侧的表达式 严格来说是存储在内存中，并且明确存储地址（可寻址）的数据
右值：只能位于赋值号(=)右侧的表达式，严格来说是提供数据值数据（不一定能寻址, 如存储在寄存器中的数据)

左值引用：如果初始化值是A的左值，则用A&
右值引用：如果初始化值是A的右值，则用A&&
 */

struct Widget{};
Widget makeWidget() { return Widget(); }//类工厂函数

int main() {
    int a = 5;//a 为左值
    // error: 5 = a; 5为一个字面值是一个右值
    
    Widget&& var1 = Widget();// var1的类型是右值引用， 但是作为左值
    auto&& var2 = var1;// var2的类型是左值引用。因为var2声明为引用指向了前一个左值！！！
    vector<int> v = {1, 2, 3};
    auto&& var = v[0];// std::vector::opterator[] 返回值是元素左值， 所以val的类型是左值引用
    Widget&& var3 = makeWidget();// var3作为左值，但是它的类型是右值引用
    Widget var4 = static_cast<Widget&&> (var1);//var4 是左值，但是它的类型是右值引用

    cout << typeid(var1).name() << endl;
    cout << typeid(var2).name() << endl;
    cout << typeid(var).name() << endl;
    cout << typeid(var3).name() << endl;
    cout << typeid(var4).name() << endl;
    

    return 0;
}
