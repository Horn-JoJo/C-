#include <iostream>
#include <cstring>
using namespace std;

class A {
public:
    void set_name(string t) {
        this->name = t;
    }
    void set_age(int t) {
        this->age = t;
    }
    void set_sex(int t) {
        this->sex = t;
    }
    void show() {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Sex: " << this->sex << endl;
    }
private:
    string name;
    int age;
    int sex;
};

int main() {
    A* p = new A();
    p->set_name("Alice");
    p->set_age(16);
    p->set_sex(1);
    p->show();

    return 0;
}
