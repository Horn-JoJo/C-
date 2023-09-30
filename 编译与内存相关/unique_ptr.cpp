#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }
};

int main() {
    unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << P1->area() << endl;

    unique_ptr<Rectangle> P2;
    //无法拷贝构造：unique_ptr(const unique_ptr&) = delete;
    //unique_ptr<Rectangle> P2(P1);
    
    //移动拷贝构造可以！！！
    //unique_ptr<Rectangle> P2(move(P1));
    
    //无法赋值构造：unique_ptr& operator=(const unique_ptr&) = delete;
    //P2 = P1;

    //移动赋值构造也可以！！！
    P2 = move(P1);

    cout << P2->area() << endl;
    //Segmentation fault
    //cout << P1->area() << endl;//已经传递，P1无所有权
    
    return 0;

}
/*
 unique_ptr相关源码：

// Disable copy from lvalue.不允许复制，体现专属所有权语义
unique_ptr(const unique_ptr&) = delete;
unique_ptr& operator=(const unique_ptr&) = delete;

// Move constructor.体现专属所有权语义和只移型别
// 只允许使用移动拷贝构造函数
// 如果复制一个unique_ptr对象，会将源unique_ptr对象管理的资源release掉
unique_ptr(unique_ptr&& __u) noexcept
: _M_t(__u.release(), std::forward<deleter_type>(__u.get_deleter())) { }

// 这个也是移动拷贝构造函数
// 只是使用的类型是可以隐式转换的其他unique_ptr对象
template<typename _Up, typename _Ep, typename = _Require<
		__safe_conversion_up<_Up, _Ep>,
typename conditional<is_reference<_Dp>::value,
	is_same<_Ep, _Dp>,
	is_convertible<_Ep, _Dp>>::type>>
unique_ptr(unique_ptr<_Up, _Ep>&& __u) noexcept
: _M_t(__u.release(), std::forward<_Ep>(__u.get_deleter()))
{ }

// Assignment，也可以说明是专属所有权语义和只移型别
unique_ptr& operator=(unique_ptr&& __u) noexcept
{
	// __u.release()释放并返回源unique_ptr对象管理的资源
	// reset是将__u.release()返回的资源赋给目标（当前）unique_ptr对象
	reset(__u.release());
	get_deleter() = std::forward<deleter_type>(__u.get_deleter());
	return *this;
}

// 析构函数，调用析构器析构掉管理的资源，并将__ptr指向nullptr
~unique_ptr()
{
	auto& __ptr = _M_t._M_ptr();
	if (__ptr != nullptr)
		get_deleter()(__ptr);
	__ptr = pointer();
}

void reset(pointer __p = pointer()) noexcept
{
    using std::swap;
    swap(_M_t._M_ptr(), __p);
    if (__p != pointer() get_deleter()(__p);
}

 */
