[TOC]
# C++语法学习
## C++基础入门
### 1. C++初识
#### 1.1 第一个c++c程序：输出hello world!!!
```C++ []
#include <iostream>
using namespace std;

int main() {
    cout << "hello world!!!" << endl;
    return 0;
}
```
#### 1.2 注释
- 单行注释：`//`
- 多行注释：`/**/`
#### 1.3 变量
- 意义：给一段指定的内存空间取别名，方便操作这段内存
- 语法：`数据类型 变量名 初始值;`
```C++
int a = 10;在一个大小为4字节的空间存储数字10，这段空间的起始地址为a
cout << a << endl;
```
#### 1.4 常量
- 作用：用于记录程序中不可更改的数据
- C++定义常量方式：
    - #define 宏常量：`#define 常量名 常量值`
        - 通常文件上方定义，表示一个常量
    - const修饰的变量const数据类型 变量名 = 常量值
        - 通常在变量前加关键字const, 修饰该变量为常量，不可更改(告知编译器) 
```C++
#define day 7
const int a = 10;
```
#### 1.5 关键字
- 作用：关键字是C++预先保留的单词(标识符)
- **在定义变量名或者常量名的时候，不要用关键字**

|  asm       | do           | if               | return      | typedef  |
|------------|--------------|------------------|-------------|----------|
| auto       | double       | inline           | short       | typeid   |
| bool       | dynamic_cast | int              | signed      | typename |
| break      | else         | long             | sizeof      | union    |
|  case      | enum         | mutable          | static      | unsigned |
| catch      | explicit     | namespace        | static_cast | using    |
| char       | export       | new              | struct      | virtual  |
| class      | extern       | operator         | switch      | void     |
| const      | false        | private          | template    | volatile |
| const_cast | float        | protected        | this        | wchar_t  |
| continue   | for          | public           | throw       | while    |
| default    | friend       | register         | true        |          |
| delete     | goto         | reinterpret_cast |  try        |          |

`提示：在给常量或者变量起名称时候，不要用C++关键字，否则会产生歧义。`
#### 1.6 标识符命名规则

## 核心
## 提高
