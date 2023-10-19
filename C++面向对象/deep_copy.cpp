#include <iostream>
using namespace std;

class Test {
private:
    int *p;
public:
    Test(int val) {
        p = new int(val);
        cout << "Test(int val)" << endl;
    }
    ~Test() {
        if (p != NULL) {
            delete p;
        }
        cout << "~Test()" << endl;
    }
    //定义拷贝构造函数！！！
    Test(const Test& tmp) {
        p = new int(*tmp.p);
        cout << "Test(const Test& tmp)" << endl;
    }
};

int main() {
    Test a(100);
    Test b = a;

    return 0;
}
