#include <iostream>
using namespace std;

template <typename T>
class Complex {
public:
    //构造函数
    Complex(T a, T b) {
        this->a = a;
        this->b = b;
    }
    //运算符重载
    Complex<T> operator+(Complex& c) {
        Complex<T> t(this->a + c.a, this->b + c.b);
        cout << t.a << " " << t.b << endl;
        return t;
    }
private:
    T a;
    T b;
};

int main() {
    Complex<int> a(10, 20);
    Complex<int> b(20, 30);
    Complex<int> c = a + b;

    return 0;
}
