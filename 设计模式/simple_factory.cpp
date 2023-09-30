#include <iostream>
#include <vector>
using namespace std;

//定义产品的虚类
class Operation {
public:
    int val1, val2;
    virtual double GetResult() {
        int res = 0;
        return res;
    }
};

//实现具体的产品类
class Add_Operation: public Operation {
public:
    virtual double GetResult() {
        return val1 + val2;
    }   
};

class Sub_Operation: public Operation {
public:
    virtual double GetResult() {
        return val1 - val2;
    }
};

class Mul_Operation: public Operation {
public:
    virtual double GetResult() {
        return val1 * val2;
    }
};

class Div_Operation: public Operation {
public:
    virtual double GetResult() {
        return val1 / val2;
    }
};

class Factory {
public:
    static Operation* CreateProduct(char op) {
        switch(op) {
        case '+':
            return new Add_Operation();
        case '-':
            return new Sub_Operation();
        case '*':
            return new Mul_Operation();
        case '/':
            return new Div_Operation();
                
        default: 
            return new Add_Operation();
        }
    }
};

int main() {
    int a, b;
    cin >> a >> b;

    Operation* p = Factory::CreateProduct('+');
    p->val1 = a;
    p->val2 = b;
    cout << p->GetResult() << endl;

    p = Factory::CreateProduct('-');
    p->val1 = a;
    p->val2 = b;
    cout << p->GetResult() << endl;
    
    p = Factory::CreateProduct('*');
    p->val1 = a;
    p->val2 = b;
    cout << p->GetResult() << endl;

    p = Factory::CreateProduct('/');
    p->val1 = a;
    p->val2 = b;
    cout << p->GetResult() << endl;

    return 0;
}
