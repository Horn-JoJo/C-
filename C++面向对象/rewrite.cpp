#include <iostream>
using namespace std;

//重载：同名不同参数，不同类型，不在乎返回值类型！！！
class A {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    void add(float a, float b) {
        cout << a + b << endl;
    }
    
    //这里编译会报错！！！
    //void add(int a, int b) {
      //  return a + b;
    //}

};

int main() {
    A a;
    cout << a.add(11, 33) << endl;
    cout << a.add(22.0, 44.1) << endl;
    a.add((float)344.555, (float)888.99);

    return 0;
}
