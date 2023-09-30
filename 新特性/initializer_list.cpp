#include <initializer_list>
#include <iostream>
#include <vector>
using namespace std;

void f(initializer_list<int> list) {
    for (auto x : list) cout << x << endl;
}

int main() {
    f({1, 2, 3, 4, 5});//初始化列表作为形参
    vector<int> arr1 = {1, 3, 4, 5, 66};//初始化列表构造函数
    vector<int> arr2{3, 5, 8, 90};

    return 0;
}
