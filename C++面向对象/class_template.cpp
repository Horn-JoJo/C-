#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Queue {
private:
    int hh;
    int tt;
    vector<T> q;
public:
    Queue(int h = 0, int t = -1, int capacity = 1000) : hh(h), tt(t), q(vector<T>(capacity)) {

    }

    void push(T& x) {
        q[++tt] = x;
    }

    void pop() {
        q[hh++];
    }

    T& front() {
        return q[hh];
    }

    void empty() {
        if (hh <= tt) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
};

int main() {
    Queue<char> q;
    for (int i = 0; i < 5; i++) {
        char a;
        cin >> a;
        q.push(a);
        cout << q.front() << endl;
        q.pop();
        q.empty();
    }
    return 0;
}
