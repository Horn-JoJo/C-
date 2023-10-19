#include <iostream>
using namespace std;

class Base {

};

class Derive: public Base {

};

int main() {
    Base* p1 = new Derive();
    Derive* p2 = new Derive();

    p1 = dynamic_cast<Base*>(p2);
    if (p1 == NULL) {
        cout << "NULL" << endl;
    } else {
        cout << "NOT NULL" << endl;//输出
    }

    return 0;
}
