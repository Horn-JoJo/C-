#include <iostream>
using namespace std;

class A {
public:
    A(int t) : val(t) {

    }
private:
    int val;
    friend ostream& operator<<(ostream& _cout, const A& tmp);//声明为类的友元函数
};

ostream& operator<<(ostream& _cout, const A& tmp) 
{
    _cout << tmp.val;
    return _cout;
}

int main() {
    A a(666); 
    cout << a << endl;//666 
    return 0;
}
