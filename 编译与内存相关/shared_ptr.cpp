#include <iostream>
using namespace std;
#include <memory>

class Rectangle {
	int length;
	int breadth;

public:
	Rectangle(int l, int b)
	{
		length = l;
		breadth = b;
	}

	int area()
	{
		return length * breadth;
	}
};
int main()
{

	shared_ptr<Rectangle> P1(new Rectangle(10, 5));
	cout << P1->area() << endl;
	shared_ptr<Rectangle> P2;
	P2 = P1;

	cout << P2->area() << endl; // 50
	cout << P1->area() << endl; // 50
	cout << P1.use_count() << endl; // 2
	cout << P2.use_count() << endl; // 2
	return 0;
}


/*
共享指针类的部分源码
template<class _Tp>
class shared_ptr {
	typedef _Tp element_type;

private:
	element_type*      __ptr_;
	__shared_weak_count* __cntrl_;

	...
}
*/
