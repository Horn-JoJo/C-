#include <iostream>
using namespace std;

int setValue() {
    return 666;
}

int global = 1010;
int& setGlobal() {
    return global;
}

int main() {
#if 0
    int x = 555;//ok
    int* y = x;//ok
    int* z = &666;//666没有地址!!!!!!!
    665 = x;//666为临时变量没有地址，不能作为左值!!!!!
    int a = 9;//ok
    int b = 4;//ok
    int c = a + b;//ok
    a + b = 42;//error 
#endif
    setGlobal() = 9999;//！！！！！返回值为引用！！！因此返回的结果就是global！！！它是能够取到地址的！！！
    //setValue() = 6666;//error
    cout << setGlobal() << endl;
    return 0;
}
