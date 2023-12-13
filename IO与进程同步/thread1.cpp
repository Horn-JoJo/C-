#include <iostream>
#include <thread>
using namespace std;

class Test {
    private:
    void func1(const std::string s1, int i) {
        std::cout << s1 << ' ' << i << std::endl;
    }
    public:
    void func2() {//类中的该成员函数调用另一个成员函数，绑定了this!!!
        std::thread t1(&Test::func1, this, "dog", 0);
        t1.join();//这里为join时，就会先去执行func1，执行完后再去执行fun2后续逻辑。那么结果始终是dog 0\n func2
        //t1.detach(); 当这里为detach打印的结果是不可预知的！！！因为fun2执行完了，这里t1对象已经被销毁了，可能执行fun1时会出现问题！！！
        std::cout << "func2" << std::endl;
    }
};

int main() {
    Test a;
    a.func2();
    return 0;
}
