#include <iostream>
using namespace std;

class A {
public:
    static void printMsg() {
        cout << "welcome to A" << endl;
    }
    
};

int main() {
    A::printMsg();

    return 0;
}
