#include <iostream>
using namespace std;

class Test {
private:
    int value;
public:
    Test() {
        cout << "[Test] constructor" << endl;
    }

    void* operator new(size_t size) {
        cout << "[Test] operator new" << endl;
        return NULL;
    }
};

int main() {
    Test* t = new Test();//打印构造函数和重载new运算符里的输出内容
    return 0;

    return 0;
}
