#include <iostream>
using namespace std;

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
int main() {
    int a, b;
    cout << "please input:" << endl;;
    cin >> a >> b;

    cout << "max value = " << MAX(a, b) << endl;
    cout << "min value = " << MIN(a, b) << endl;
    return 0;
}
