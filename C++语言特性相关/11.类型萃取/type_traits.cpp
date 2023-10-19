#include <cstdio>
#include <iostream>
using namespace std;

template <typename _Tp>
struct Remove_reference {
    typedef _Tp type;
};

template <typename _Tp> 
struct Remove_reference<_Tp&> {
    typedef _Tp type;
};

template <typename _Tp> 
struct Remove_reference<_Tp&&> {
    typedef _Tp type;
};

template <typename T>
struct Remove_reference<T>::type&& move(T&& t) {
    return static_cast<remove_reference_t<T>&&>(t);
}

int main() {

    return 0;
}
