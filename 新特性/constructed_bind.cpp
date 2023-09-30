#include <iostream>
#include <system_error>
#include <tuple>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    auto [x, y, z] = std::make_tuple(1, 1.23, "hello world!");
    cout << x << ' ' << y << ' ' << z << endl;

    auto [a, b] = std::make_pair(23, 56);
    cout << a << ' ' << b << endl;

    int arr[3] = {1, 2, 3};
    auto [c, d, e] = arr;
    cout << c << ' ' << d << ' ' << e << endl;

    auto [f, g] = Point(5, 6);
    cout << f << ' ' << g << endl;


    return 0;
}
