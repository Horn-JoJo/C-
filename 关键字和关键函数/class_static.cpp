#include <iostream>
using namespace std;


class A {
public:
    static int i;
        
};
int A::i = 100;

int main() {
    A g1;
    g1.i = 999;//可以 但是不提倡！！！
    cout << A::i << endl;    

    return 0;
}
