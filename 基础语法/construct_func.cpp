#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    //构造函数
    MyClass() {
        value = 0;//初始化成员变量
        cout << "constructor called." << endl;
    }

    //带参数的构造函数
    MyClass(int val) {
        value = val;//使用参数初始化成员变量
        cout << "Parameterized constructor called." << endl;
    }

    //成员函数
    void display() {
        cout << "value: " << value << endl;
    }
};

int main() {
    MyClass obj1;//调用无参构造函数
    MyClass obj2(42);//调用带参数的构造函数
    
    obj1.display();
    obj2.display();

    return 0;
}
