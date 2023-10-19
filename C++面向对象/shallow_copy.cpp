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
    }
};

int main() {
    Test a(100);
    Test b = a;//这里只是浅拷贝，只拷贝了栈中的的数组，堆中的数据是指向同一个的！！！但是析构会重复释放同一个堆上的内容，因此程序会崩溃！！！

    return 0;
}
