#include <iostream>
using namespace std;

int g_var = 999;//全局变量
static char* gs_var;//静态全局变量
extern int test();//引用外部文件的test函数

int main() {
    int var;//局部变量
    static int s_var = 0;//静态局部变量
    cout << g_var << endl;
    test();
    cout << g_var << endl;
    return 0;
}

