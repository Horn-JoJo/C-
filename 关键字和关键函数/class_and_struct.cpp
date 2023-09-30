#include <iostream>
using namespace std;

struct A{};//public
class B: A{};//private 继承
struct C : B{};//public 继承

int main() {
    
    return 0;
}

