#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::vector<int> vect(5);
    for (auto it = vect.begin(); it != vect.end(); ++it) cin >> *it;
    for (auto it = vect.begin(); it != vect.end(); ++it) cout << *it << ' ';
    cout << endl;
    auto ptr = [](double x) { return x * x; };//std::function<double(double)>函数对象
    cout << ptr(3.14) << endl;
    return 0;
}
