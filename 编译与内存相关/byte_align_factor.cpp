#include <iostream>
using namespace std;


# pragma pack(16)
class A {
    int a;
    double b;
    char c;
};

int main() {

    cout << sizeof(A) << endl;
    //对齐系数：       1    4 + 8 + 1 = 13
    //对齐系数:        2    4 + 8 + 4 = 14
    //x86默认对齐系数：4    4 + 8 + 4 = 16
    //x64默认对齐系数：8    8 + 8 + 8 = 24
    //对齐系数：       16   8 + 8 + 8 = 24

    return 0;
}
