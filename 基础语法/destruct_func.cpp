#include <iostream>
using namespace std;

class MyResource {
public:
    MyResource() {
        cout << "init MyResource" << endl;
    }

    ~MyResource() {
        //在析构函数中执行清理工作
        cout << "release MyResource" << endl;
    }
};


class MyClass {
private:
    MyResource* res;

public:
    MyClass() {
        res = new MyResource();
        cout << "MyResource construct called." << endl;
    }

    ~MyClass() {
        delete res;
        cout << "MyResource destruct called." << endl;
    }
};

int main() {
    MyClass obj;

    //通过对象访问其成员
    //...
    
    //对象超出作用域，析构函数自动被调用，资源被释放
    return 0;
}
