#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int& countRef = count;
    //初始化表达式是引用，而auto没有加引用标志&，则myAuto指向int类型，而不是int&类型
    auto myAuto = countRef;
    //这里myAuto1是引用类型！！！是count的别名
    auto& myAuto1 = countRef;

    countRef = 11;
    cout << count << endl;//11 

    myAuto = 12;
    cout << count << endl;//11
    
    cout << myAuto << endl;//12
    
    myAuto1 = 66;
    cout << count << endl;

    return 0;
}
