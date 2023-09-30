#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[4] = {4, 2, 3, 1};
    //对arr中的数组元素进行排序
    sort(arr, arr + 4, [=](int x, int y) -> bool { return x < y; });
    auto f = [&](int x) -> int {
        return arr[0] + x;
    };
    cout << f(100) << endl;
    for (auto& x : arr) cout << x << ' ';
    cout << endl;

    return 0;
}
