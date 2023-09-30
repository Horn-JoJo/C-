#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    char buf[100];
    int* p = new (buf) int(101);
    cout << *(int*)buf << endl;

    return 0;
}
