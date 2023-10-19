#include <type_traits>
//当noexcept用来声明函数时，默认是noexcept(true) 编译器会检查是否异常，如果异常，则直接异常退出，不打印异常信息， 如果设置为noexcept(false)，则异常会打印异常信息并退出
template<typename _Tp>
constexpr _Tp&& forward(typename std::remove_reference<_Tp>::type& __t) noexcept {
    return static_cast<_Tp&&>(__t);
}

template<typename _Tp>
constexpr _Tp&& forward(typename std::remove_reference<_Tp>::type&& __t) noexcept(true) {
    static_assert(!std::is_lvalue_reference<_Tp>::value, "template argument substituing _Tp is an is_lvalue_reference type");
    return static_cast<_Tp&&>(__t);
}

int main() {

    return 0;
}
