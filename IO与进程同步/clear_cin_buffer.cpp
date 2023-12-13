#include <iostream>
using namespace std;

int main() {
    int a;
    char ch[80];
    cin >> a;
    cin.getline(ch, 80);
    cout << a << endl;
    cout << ch << endl;

    return 0;
}
//a 
//0 因为前一个输入由个换行符没有清除，作为了ch的第一个字母，这样就结束了第二次的输入
