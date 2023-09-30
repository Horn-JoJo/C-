#include <iostream>
#include <cstring>
using namespace std;

void size_of(char arr[]) {
    cout << sizeof(arr) << endl;//算的是指针的大小
    cout << strlen(arr) << endl;
}

struct flexArray {
    int val;
    int array[];
};

int main() {
    char arr[20] = "hello";
    cout << sizeof(arr) << endl;//20 算的是字符数组总共有多大
    cout << strlen(arr) << endl;//5 计算的是字符串的长度
    size_of(arr);//8 5

    ///sizeof传入的参数如果是表达式，则不会对表达式进行计算！！！因为是在编译时期计算字节大小的！！！
    int a = 5;
    sizeof(++a);//编译时候进行计算变量的字节大小，不会对表达式进行计算
    cout << a << endl;//5
    
    char* s = "12345678";
    char *p = s;
    //strlen会对表达式进行计算 运行时计算大小的
    cout << strlen(++p) << endl;//7字节
    //cout << *p << endl;//‘2’
    printf("%s\n", p);

    cout << sizeof(struct flexArray) << endl;// 4 
    return 0;
}
