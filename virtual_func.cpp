#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "animal speaks." << endl;
    }
};


class Dog: public Animal {
public:
    void speak() override {
        cout << "Dog sparks." << endl;
    }
};


class Cat: public Animal {
    void speak() override {
        cout << "Cat meows." << endl;
    }
};

int main() {
    Animal* ptr1 = new Dog();
    Animal* ptr2 = new Cat();

    ptr1->speak();
    ptr2->speak();

    delete ptr1;
    delete ptr2;

    return 0;
}
