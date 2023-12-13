#include <iostream>
#include <thread>
#include <string>
using namespace std;
void fn2 (string st2) {
    cout << st2 << endl;
}

void fn1 (string st1) {
    cout << st1 << endl;
}

int main() {
    thread thr1(fn1, "11111111\n");
    thread thr2(fn2, "22222222\n");
    //thr1.join();
    //thr2.join();
    return 0;
}

/* 
当没有join或者detach时，会报如下错误
terminate called without an active exception
11111111
Aborted

否则正常打印
11111111
22222222
*/

