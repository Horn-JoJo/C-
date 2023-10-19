#include <iostream>
using namespace std;

class A {
private:
    int val;
public:
    A(int t) : val(t) {//带参数构造函数
        cout << "A(int t)" << endl;
    }

    A(const A& t) //拷贝构造函数 
    {
        cout << "A(const A& t)" << endl;
        val = t.val;
    }

    A& operator=(const A& t) {//赋值运算符
        cout << "A& operator=(const A& t)" << endl;
        val = t.val;
        return *this;
    }

    void fun(A t) {

    }
};

int main() {
    A ex1(1);//A(int t)
    A ex2(2);//A(int t)
    A ex3 = ex1;//A(const A& t)
    ex2 = ex1;//A& operator=(const A& t)
    ex2.fun(ex1);//A(const A& t)

    return 0;
}
