#include <iostream>
#include <cstring>
using namespace std;

void fun(char const* p) {
    cout << "fun(char const* p)" << endl;
}

void fun(int t) {
    cout << "fun(int t)" << endl;
}

int main() {
    fun(nullptr);
    //fun(NULL);// call to fun is ambiguous
    
    return 0;
}
