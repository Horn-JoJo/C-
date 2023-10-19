#include <iostream>
using namespace std;

template <typename T>
void f(T&& param);

template <typename T>
class Test {
public:
    Test(Test&& rhs);
};

int main() {


    return 0;
}
