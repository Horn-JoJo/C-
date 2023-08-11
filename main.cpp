#include <iostream>
using namespace std;

#pragma pack(16)

struct s {
    int a;//1
    double b;//8
    char c;//1
};

int main() {
    cout << sizeof(s) << endl;
}
