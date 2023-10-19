#include <iostream>
using namespace std;

class A {
private:
    static int s_var;//不影响类的大小
    const int c_var;//4字节
    int var; 
    char c;
public:
    A(int t): c_var(t)  {//const类型变量必须用初始化列表来初始化？对的！！！
        //c_var = t; 
    }
    ~A() {}
};

class B {

};
int main() {
    A a(555);
    cout << sizeof(a) << endl;//12字节：整体对齐，按照min(成员变量中字节数最大，机器位置) 的倍数进行对齐。局部按照当前类型字节大小的整数倍对齐
    cout << sizeof(B) << endl;
    return 0;
}
