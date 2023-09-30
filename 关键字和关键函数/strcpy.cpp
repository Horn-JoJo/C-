#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int var = 0x11112222;
    char arr[10];
    cout << "Address: var " << &var << endl;
    cout << "Address: arr " << &arr << endl;
    //这里拷贝目标数组arr空间不够，arr拷贝没有\0结束，可能输出的结果有乱码！
    strcpy(arr, "hello world!");
    cout << "var:" << hex << var << endl;
    cout << "arr:" << arr << endl;
    return 0;
}

// 现象："d!"这三个字符可能存储到var变量的低三位存储空间，导致报错！！！
