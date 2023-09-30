#include <iostream>

int main()
{
#if __has_include(<cstdio>)
    printf("c program\n");
#endif

#if __has_include("iostream")
    std::cout << "c++ program" << std::endl;
#endif

    return 0;
}

