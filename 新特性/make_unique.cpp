//c++11中有make_shared 但是没有make_unique, C++14中增加了！！！
#include <iostream>
#include <memory>
using namespace std;

struct A{};
int main() {
    std::unique_ptr<A> ptr = std::make_unique<A>();
    return 0;
}
