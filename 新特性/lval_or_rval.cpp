# include <iostream>
using namespace std;

int main() {
    int var = 42;
    int& l_var = var;//左值：能够获得到对应变量结果的地址
    //int&& r_var = var;//error
    int&& r_var1 = var + 10;//右值：不能够获得对应结果的地址, 将r_var1绑定到了求和结果上！！！
    int&& r_var2 = std::move(var);//移动了临时变量的地址，不能够获取到对应的地址, 将r_var2绑定到了左值变量的右值引用上（move就是为了获取左值变量的右值引用）
    return 0;
}
