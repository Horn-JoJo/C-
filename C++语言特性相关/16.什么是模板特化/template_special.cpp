#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

//函数模板
template <class T>
bool compare(T t1, T t2) {
    cout << "通用版本:";
    return t1 == t2;
}

template <> //函数木本特化
bool compare(char* t1, char* t2) {
    cout << "特化版本:";
    return strcmp(t1, t2) == 0;
}

int main(int argc, char* argv[]) {
    char arr1[] = "hello";
    char arr2[] = "world";
    cout << compare(123, 123) << endl;
    cout << compare(arr1, arr2) << endl;

    return 0;
}
