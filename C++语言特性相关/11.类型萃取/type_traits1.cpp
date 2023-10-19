#include <cstdlib>
#include <iostream>
#include <type_traits>
#include <string>

//定义一个基本的TypeProcessor结构体，用于默认情况下处理任意类型
template <typename T, typename = void>
struct TypeProcessor {
    static void process(const T& value) {//常量左值引用
        std::cout<< "Default processing: " << value << std::endl;
    }
};

//部分转化 TypeProcessor 结构体来处理字符串类型
template <typename T>
struct TypeProcessor<T, typename std::enable_if<std::is_same<T, std::string>::value>::type> {
    static void process(const T& value) {
        std::cout << "Processing string: " << value << std::endl;
    }
};

template <typename T>
struct TypeProcessor<T, typename std::enable_if<std::is_integral<T>::value>::type> {
    static void process(const T& value) {
        std::cout << "Processing integer: " << value << std::endl;
    }
};

int main() {
    TypeProcessor<int>::process(42);
    TypeProcessor<double>::process(3.14);
    TypeProcessor<std::string>::process("hello");

    return 0;
}
