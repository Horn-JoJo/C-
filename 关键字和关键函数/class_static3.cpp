#include <iostream>
using namespace std;

class A {
    int i;
public:
    A() {
        i = 0;
        cout << "A constructed." << endl;
    }
    ~A() {
        cout << "A Deconstruted." << endl;
    }
};

class B: public A {
    int i;
public:
    B() {
        i = 0;
        cout << "B constructed." << endl;
    }
    ~B() {
        cout << "B Deconstruted." << endl;
    }
};

int main() {
    int x = 0;
    if (x == 0) {
        A a;
        static B b;
    }
    cout << "end " << endl;

    return 0;
}
