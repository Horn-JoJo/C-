#include <iostream>
using namespace std;
typedef char* ptr;//定义char* 为ptr类型
#define PTR char* //用PTR表示char* 类型
int main () {
    ptr a, b, c;//这里给char* 重新定义了一个新的指针类型，因此每个成员都是指针！！！
    PTR x, y, z;//这里只是第一个为char* 类型的指针，后面两个为char字符类型！！！因为这里只是char* 的宏替换
    printf("sizeof a :%zu\n", sizeof(a));
    printf("sizeof b :%zu\n", sizeof(b));
    printf("sizeof c :%zu\n", sizeof(c));
    printf("sizeof x :%zu\n", sizeof(x));
    printf("sizeof y :%zu\n", sizeof(y));
    printf("sizeof z :%zu\n", sizeof(z));

    return 0;
}
