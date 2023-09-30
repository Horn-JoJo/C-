#include <iostream>
#include <any>
using namespace std;

int main() {
    any t = 100;
    cout << any_cast<int>(t) << endl;

    t = string("9999");
    cout << any_cast<string>(t) << endl;

    return 0;
}
