#include <iostream>
using namespace std;

#if 0
//使用final关键字禁用类继承
class Base final {

};

class A : public Base {//这里编译时会报错！！！

};
#endif

//使用虚继承，友元，私有构造函数来实现禁止类继承
template <class T>
class B {
    friend T;//声明C类为友元类，因此C类可以访问该类的私有成员以及私有函数
    B() { cout << "B::B()" << endl; }
    ~B() { cout << "B::~B()" << endl; }
};

class C : virtual public B<C> {
public:
    C() { cout << "C::C()" << endl; }
    ~C() { cout << "C::~C()" << endl; }
};

//当基类(直接基类)继承虚基类（间接基类）是虚继承时（用virtual修饰），则子类实例化的构造过程是：D类去调B类构造B()，D调C类构造()，然后调自己构造D()，但是D类没有权限访问B()，所有会编译报错
//当基类继承虚基类是公有继承时（不用virtual修饰），则子类实例化的构造过程是：先实例C类（先构造B类B()，然后构造自己C()），然后调用自己构造D()
class D : public C {//这里编译器会检查继承的类中是否存储在私有构造函数，如果有，编译报错！！！
public:
    D() { cout << "D::D()" << endl; }
    ~D() { cout << "D::~D()" << endl; }
};

int main() {
    //A a;
    //当没有virtual 修饰时，此时的构造顺序：先顺序构造继承的类，然后构造自己 B::B() C::C() C::~C() B::~B()
    //当有virutal修饰时, 同上顺序！
    //C c;//因为C类是B类的友元，因此可以创建示例成功
    D d;
    return 0;
}
