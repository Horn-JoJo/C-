#include <iostream>
using namespace std;

class A {};
class B {
public:
    B() {};
    ~B() {};
    B (const B& t) {};
    B& operator=(const B& t) {};
    B* operator&() { return this; };
    const B* operator&() const { return this; };
};


int main() {
    cout << sizeof(A) << endl;
    // A<=>B
    B p;//B* p = new B();注意区别！！！
    cout << sizeof(B) << ' ' << sizeof(p) << endl;
    return 0;
}
