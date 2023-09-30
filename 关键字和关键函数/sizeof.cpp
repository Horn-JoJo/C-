#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int x = 9;
    sizeof(x++);
    cout << x << endl;
    
    cout << sizeof(1 == 1111) << endl;
    return 0;
}
