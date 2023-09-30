#include <iostream>
using namespace std;


struct bit_field {
    short a;//MSVC: 2字节
    char b;//MSVC: 需要字节对齐，保证下面int c的起始位置是alignof(int)的整数倍，需要填充1字节
    int c:1;//MSVC: 4字节，使用1位，剩余31位
    char d:4;//MSVC: 需要字节对齐，保证下面short e的起始位置是alignof(short)的整数倍, 需要填充1字节 使用4位，剩余12位
    short e:7;//MSVC: 2字节 
    //MAVC: 已经是alignof(int)的整数倍
};

struct bit_field1 {
    short a;//clang|gcc: 2字节
    char b;//clang|gcc: 1字节，不用字节对齐
    int c:1;//clang|gcc: 分配1字节，使用了1比特位，剩余7比特位。
    char d:4;//clang|gcc: 上述分配空间剩余的比特位能够存储下来4比特位，剩余3比特位
    short e:7;//clang|gcc：上述剩余的比特位不能装下7个比特位，因此开辟新的一字节来存储，使用7比特位，剩余1比特位
    //2 + 1 + 1 + 1 = 5字节，为了保证结构体大小是alignof(int)的整数倍，因此补充3字节对齐
};
int main() {
    cout << sizeof(bit_field) << endl;//MSVC：12字节; clang|gcc: 8字节 
    
    return 0;
}

/*
1. MSVC: 需要满足每个类型的起始位置都是对应类型的alignment的整数倍
2. clang|gcc: 在存储的时候不需要满足每个类型起始位置的是其对应的alignment的整数倍。只需要在最后补充字节保证结构体是最大alignment的整数倍
 */
