#include <iostream>

//remove_reference 具体实现 定义了remove_reference 结构体！
//原始的，最通用的版本
template <typename T> struct remove_reference {
    typedef T type;//并将其类型定义为type
};

//部分版本特例化(声明结构体显示声明实例类型！！！)，将用于左值引用和右值引用
//版本1
template <class T> struct remove_reference<T&> {//左值引用
    using type = T;
};

//版本2
template <class T> struct remove_reference<T&&> {//右值引用
    typedef T type;
};

//这里是move函数的实现，返回值类型为 remove_reference<T>::type&& 前面添加typename是为了告知编译器这是类型！！！
template <typename T>
typename remove_reference<T>::type&& move(T&& t) {//这里不管实参传入的是左值还是右值T&& 如果T为左值则t为左值，否则为右值，也就是说t是左值还是右值完全取决于T的类型(引用折叠的知识) 然后调用static_cast<...>转化成右值！！！具体步骤是先确定其类型，然后添加&&来表示右值引用
    return static_cast<typename remove_reference<T>::type&&>(t);//这里T为左值引用是会使用特例化版本1的type, 如果为右值引用会使用特例化版本2的type
}


int main() {
    int i;
    remove_reference<decltype(42)>::type a = 20;//使用原版本
    remove_reference<decltype(i)>::type b = 88;//左值引用特例版本
    remove_reference<decltype(std::move(i))>::type c = 999;//右值引用特例版本
    //这里打印的都是int
    std::cout << typeid(a).name() << ' ' << typeid(b).name() << ' ' << typeid(c).name() << std::endl;
    std::cout << a << ' ' << b << ' ' << c << ' ' << std::endl;
    return 0;
}
