#include <iostream>
using namespace std;

struct A {
    char c;
    int val;
    A(char c_t, int t) : c(c_t), val(t) {}
  
    friend bool operator==(const A& t1, const A& t2);
    /*
    bool operator==(const A& t1) {
        return this->c == t1.c && this->val == t1.val;
    }*/ 
    /*bool operator==(const A& t1);*/
};

/*
//这是重载A内部的==运算符
bool A::operator==(const A& t1) {
    return this->c == t1.c && this->val && t1.val;
}*/

//这是是重载选举运算符==
bool operator==(const A& t1, const A& t2) {
    return t1.c == t2.c && t1.val == t2.val;
}

int main() {
    A ex1('a', 90), ex2('b', 80);
    if (ex1 == ex2) {
        cout << "ex1 == ex2" << endl;
    } else {
        cout << "ex1 != ex2" << endl;
    }

    return 0;
}
