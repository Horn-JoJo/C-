#include <iostream>
#include <ostream>
using namespace std;

int main() {
    //局部变量声明
    char var = 'D';

    switch (var) {
        case 'A':
            int cnt = 0;//定义变量
            cout << "Excellent." << endl 
                 << cnt;
            break;
        case 'B':
        case 'C':
            ++cnt;
            cout << "Good." << endl 
                 << cnt;
            break;
        case 'D':
            cout << "Not bad." << endl 
                 << cnt;
        case 'F':
            cout << "Bad." << endl 
                 << cnt;
        default:
            cout << "Bad." << endl 
                 << cnt;
    }

    return 0;
}
