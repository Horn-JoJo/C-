#include <iostream>
using namespace std;

#define MIN(a, b) ({\
    typeof(a) _min1 = (a);\
    typeof(b) _min2 = (b);\
    (void) (&_min1 == &_min2);\
    _min1 < _min2 ? _min1 : _min2;})

#define MAX(a, b) ({\
    typeof(a) _max1 = (a);\
    typeof(b) _max2 = (b);\
    (void) (&_max1 == &_max2);\
    _max1 > _max2 ? _max1 : _max2; })

int main() {
    int a = 5, b = 5;
    cout << MIN(++a, b) << endl;
    cout << a << endl;
    a -= 1;
    cout << MAX(a, b++) << endl;
    cout << b << endl;
    return 0;
}
