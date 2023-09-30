#include <iostream>
using namespace std;

typedef union {
    char c[10];
    char c1;//按照该类型的倍数分配大小
}u11;

typedef union {
    char c[10];
    int i;//按照该类型的倍数分配大小
}u22;

typedef union {
    char c[10];
    double d;//按照该类型的倍数分配大小
}u33;

typedef struct s1 {
    char c;// 1+7
    double d;//8字节
}s11;//16

typedef struct s2 {
    char c;//1
    char cc;//1 + 6
    double d;//8
}s22;//16

typedef struct s3 {
    char c;//1 + 7
    double d;//8 + 8
    char cc;//16 + 1 + 7
}s33;//24

int main() {
    cout << "=================union===================" << endl;
    cout << sizeof(u11) << endl;
    cout << sizeof(u22) << endl;
    cout << sizeof(u33) << endl;
    cout << "=================struct==================" << endl;
    cout << sizeof(s11) << endl;
    cout << sizeof(s22) << endl;
    cout << sizeof(s33) << endl;
    return 0;
}
