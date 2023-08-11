#include <iostream>
using namespace std;

class Myclass {
public:
    static void printMessage() {
        cout << "hello C++ world" << endl;
    }
};

int main() {
    Myclass::printMessage();

    return 0;
}
