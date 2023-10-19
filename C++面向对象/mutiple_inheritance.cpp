#include <iostream>
using namespace std;

class A {
public:
    int var1;
};

//解决方法2：声明为虚继承
class B : virtual public A {
public:
    int var2;
};

//解决方法2：声明为虚继承
class C : virtual public A{
public:
    int var3;
};

class D : public B, public C {
public:
    int var4;

    //解决方法1: 因为B类和C类都继承了A类的var1 然后D类同时继承了B类和C类
    // 因此这里直接命名冲突了，因此需要说明命名空间是在B类或者C类
    //void set_var1(int tmp) { C::var1 = tmp; }
    void set_var1(int tmp) { var1 = tmp; }
    void set_var2(int tmp) { var2 = tmp; }
    void set_var3(int tmp) { var3 = tmp; }
    void set_var4(int tmp) { var4 = tmp; }
};

int main() {
    D d;
    return 0;
}
