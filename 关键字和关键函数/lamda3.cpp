#include <iostream>
#include <cstring>
#include <functional>

auto GetFunc() {
    std::string s = "hello world!";
    return [&]() { std::cout << s << std::endl; };//这里&指向的是局部的s，当函数返回时，这时候局部变量的内容将会被销毁！！！
}

int main() {
    auto func = GetFunc();
    func();
    return 0;
}
