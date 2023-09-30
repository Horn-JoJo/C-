#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[4] = {4, 2, 3, 1};
    sort(arr, arr + 4, [=](int x, int y) -> bool { return x < y; });//会排序成功!
    
    auto f = [&](int x) -> int {
       return arr[0] + x;//没有执行这个
    };

    for (int n : arr) {
        cout << n << " ";
    }
    

    cout << endl <<  f(99) << endl;
    return 0;
}
