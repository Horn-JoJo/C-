#include <iostream>
using namespace std;

string_view test() {
    char str[] = "27877582875675";
    return {str};
}

int main() {
    string s = "123456789";
    std::string_view sv(s.c_str());
    cout << sv << endl;
    
    for (auto& ch : sv) {
        cout << ch << ' ';
    }   
    
    for (auto it = sv.begin(); it != sv.end(); ++it) {
        cout << *it << ' ' << endl;
    }
    cout << sv.find("345") << endl;

    cout << test() << endl;

    return 0;
}