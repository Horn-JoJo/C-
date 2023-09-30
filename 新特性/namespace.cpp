#include <iostream>
namespace A {
    void func() {
        std::cout<< "A func" << std::endl;
    }

    namespace B {
        namespace C {
            void func() {
                std::cout<< "C func" << std::endl;
            }
        }
    }
}

int main()  {
    A::func();
    A::B::C::func();
    return 0;
}
