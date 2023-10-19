#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    vector<int>::iterator iter = arr.begin();//定义迭代器
    for (; iter != arr.end(); ++iter) {
        cout << *iter << ' ';
    }
    return 0;
}
