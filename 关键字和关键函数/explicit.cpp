#include <iostream>
#include <cstring>
using namespace std;

// explicit关键字 用来声明显示声明类的单参构造函数

class A {
public:
    int var;
    explicit A(int tmp) {
        var = tmp;
    }
};

int main() {
    A ex(100);
    A ex1 = 10;//error: conversion from 'int' to no- scalar type 'A' requested

    return 0;
}
