#include <iostream>

using namespace std;

template <typename T>
struct Remove_reference {
    typedef T type;
    static void couttype(type value) {
        std::cout << "normal: value " << value << endl;
    }
};

template <typename T> 
struct Remove_reference<T&> {
    typedef T type;
    static void couttype(type value) {
        std::cout << "formal_arg: l_value: " << value << endl;
    }
};

template <typename T>
struct Remove_reference<T&&> {
    typedef T type;
    static void couttype(type value) {
        std::cout << "formal_arg: r_value " << value << endl;
    }
};



int main() {
    int a = 10;
    string b = "andhdhhd";
    Remove_reference<decltype('a')>::couttype('d');
    Remove_reference<typename Remove_reference<decltype(a)>::type&>::couttype(a);//左值
    Remove_reference<typename Remove_reference<decltype(a)>::type&&>::couttype(a + 999);//右值

    return 0;
}
