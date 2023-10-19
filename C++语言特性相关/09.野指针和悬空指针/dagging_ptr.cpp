#include <iostream>
using namespace std;

int main() {
    void* p = malloc(1000);
    free(p);//此时为dagging pointer
    p = NULL;

    void* q;//没有初始化 此时为野指针
    return 0;
}
