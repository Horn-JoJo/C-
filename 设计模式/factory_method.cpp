
#include <iostream>
#include <vector>
using namespace std;

//Here is the product class
class Operation {
public:
    int val1, val2;
    virtual double GetResult() {
        double ans = 0;
        return ans;
    }
};

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
        return 1.0 * val1 / val2;
    }
};

//虚基类：工厂类
class Factory {
public:
    virtual Operation* CreateProduct() = 0;
};

class Add_Factory: public Factory {
public:
    virtual Operation* CreateProduct() {
        return new Add_Operation();
    }
};

class Sub_Factory: public Factory {
public:
    virtual Operation* CreateProduct() {
        return new Sub_Operation;      
    }
};

class Mul_Factory: public Factory {
public:
    virtual Operation* CreateProduct() {
        return new Mul_Operation();
    }
};

class Div_Factory: public Factory {
public:
    virtual Operation* CreateProduct() {
        return new Div_Operation();
    }
};

int main() {
    int a, b;
    cin >> a >> b;
    Add_Factory *p_fac = new Add_Factory();
    Operation* p_pro = p_fac->CreateProduct();
    p_pro->val1 = a;
    p_pro->val2 = b;
    cout << p_pro->GetResult() << endl;

    Mul_Factory *p_fac1 = new Mul_Factory();
    Operation* p_pro1 = p_fac1->CreateProduct();
    p_pro1->val1 = a;
    p_pro1->val2 = b;
    cout << p_pro1->GetResult() << endl;

    Sub_Factory *p_fac2 = new Sub_Factory();
    Operation* p_pro2 = p_fac2->CreateProduct();
    p_pro2->val1 = a;
    p_pro2->val2 = b;
    cout << p_pro2->GetResult() << endl;

    Div_Factory *p_fac3 = new Div_Factory();
    Operation* p_pro3 = p_fac3->CreateProduct();
    p_pro3->val1 = a;
    p_pro3->val2 = b;
    cout << p_pro3->GetResult() << endl;

    return 0;
}
