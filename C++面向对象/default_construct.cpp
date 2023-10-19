#include <iostream>
using namespace std;

class A {
public:
    A() {
        var = 10;
        c = 'q';
    }
    int var;
    char c;

};

class B {
public:
    B(int _var = 100, char _c = '@') {
        var = _var;
        c = _c;
    }
    int var;
    char c;
};

class C {
public:
    int var;
    char c;
};

int main() {
    A ex;
    cout << ex.c << endl << ex.var << endl;

    B ex1;
    cout << ex1.c << endl << ex1.var << endl;
    
    C ex2;
    cout << ex2.c << endl << ex2.var << endl;

    return 0;
}
