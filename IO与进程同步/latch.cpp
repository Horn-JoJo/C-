#include <iostream>
#include <latch>

int main() {
    //latch是一种倒计时的计数器，它的值在构造函数中设置，线程中可以使用
    //初始值为2
    std::latch work_done(2);
    work_done.count_down();//以非阻塞的方式对计数器进行减1操作 接着继续往下执行
    std::cout << "1" << std::endl;
    //work_done.wait();//当计数值不为0时，就一直阻塞，直到为0才不阻塞（不会减1操作）
    //std::cout << "waiting because the counter is nozero" << std::endl;
    bool ok = work_done.try_wait();//测试内部的计数值是否为0 如果为0则返回true 否则返回false 这时还是1 
    std::cout << ok << std::endl;//ok = 0
    work_done.arrive_and_wait();//递减计数器并阻塞直到它到达0(这里会减1) 这里减1操作后变成0，就不会阻塞了！继续执行
    std::cout << "倒计时结束" << std::endl;
    return 0;
}
