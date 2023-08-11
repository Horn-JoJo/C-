#include <iostream>
using namespace std;

class Myclass {
    void print() {
        cout << "hello from Myclass!: a = " << a << endl;
    }
    int a;
    //声明一个友元函数
    friend void print(Myclass& obj);
};

//定义友元函数
void print(Myclass& obj) {
    cout << "hello form print() function!" << endl;
    obj.a = 666;//修改对象的私有变量
    obj.print();//调用对象的私有方法
}

int main() {
    Myclass obj;
    //obj.print();私有成员函数不能直接访问
    print(obj);

    return 0;
}
