#include <iostream>
using namespace std;


struct s1 {
    char array[100];//64：100->104保证下一个long型数据的起始位置是alignof(long)的整数倍
    long x;//64位：8字节；32位：4字节
};

int main() {
    cout << "======================sizeof 和 alignof 的区别 start===========================" << endl;
    int arr[10];
    cout << "sizeof(arr) : " << sizeof(arr) << endl;
    cout << "alignof(arr): " << alignf(arr) << endl;
    cout << "alignof(int): " << sizeof(int) << endl;
    cout << "======================sizeof 和 alignof 的区别 end============================" << endl;

    cout << "结构体s1对齐系数: " << alignof(struct s1) << endl;//32:4 64:8
    cout << "结构体成员中最大数据类型的对齐系数: " << alignof(long) << endl;//4 8 
    cout << sizeof(struct s1) << endl;//64位：112字节 32位：104字节
    return 0;
}

/*
自然对齐：对于标量类型，如char, int, 指针等等，其alignof等于sizeof，称作自然对齐
int arr[10];
alignof(arr) != sizeof(arr) 前者为4字节，后者为40字节

1. 填充padding, 使得保证下一个数据类型T的起始地址能够整除alignof(T);换句话说，起始位置必须是alignof(T)的整数倍.
2. 结构体的alignemnt等于其成员中最大的alignmenhgt.
3. 结构体的sizeof等于其成员中最大的alignmengt的整数倍(这个通常用来确定最后一个元素的字节数大小)

减少padding
1. 通过将alignof大的成员排在前面，按照alignof降序的顺序声明对成员变量，可以将padding减少到最小。但重排可能会导致相关联的成员离得很远，很读性变差。
*/

