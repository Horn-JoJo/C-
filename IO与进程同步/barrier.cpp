#include <iostream>
#include <unistd.h>
#include <barrier>
#include <string>
#include <thread>
#include <vector>

using namespace std;

int main() {
    //默认是初始化列表: initializer_list
    const auto workers = {"anil", "busara", "carl"};
    //cout << typeid(workers).name() << endl;//St16initializer_listIPKcE
        
    //
    auto on_completion = []() noexcept
    /*
    lamda函数 [] 里可接收外部参数 () 里是形参列表，可以自定义参数
    等价于noexcept(true) 注意: 这里括号中可以填写表达式, 值为true 则不会抛出异常，否则会抛出异常
    */ 
    {
        static auto phase = "...done\n""Cleaning up...\n";
        cout << phase;
        phase = "...done\n";
    };
    
    //ssize(workers): 求初始化列表中的元素个数！
    //barrier对象初始为3个线程同步点！
    std::barrier sync_point(std::ssize(workers), on_completion);//当ssize(workers)个线程每完成一个阶段的任务，就会执行一次on_completion函数！！！
    //
    auto work = [&](std::string name) {
        std::string product = " " + name + " worked\n";// anill workded
        std::cout << product;//ok, op << call is atomic
        //当 std::arrive_and_wait 在同步点等待时，std::arrive_and_drop 将自己从同步机制中删除
        sync_point.arrive_and_wait();
        
        //全部到达后，进行下一阶段 此时内部计数会减少1
        product = " " + name + "cleaned\n";// anill cleaned
        std::cout << product;
        sync_point.arrive_and_wait();
    };

    std::cout << "Starting...\n";
    std::vector<std::thread> threads;//线程对象数组
    for (auto const& worker : workers) {//遍历初始化列表，然后创建线程并传入参数
        threads.emplace_back(work, worker);
        sleep(1);//每个1s实例化线程对象 当线程数小于3时，每个线程会卡在第一阶段
    }
    for (auto& thread : threads) {//让主线程等待子线程结束然后回收资源
        thread.join();
    }

    return 0; 
}
/*
Starting...
这里是3个线程均执行第一阶段的任务
 anil worked
 busara worked
 carl worked
3个线程第一阶段的任务都执行完了，此时打印on_completion函数的内容
...done
Cleaning up...
此时内部计数会减少1。然后只需要两个线程执行就可以印on_completion了！！！
然后这三个线程开始执行第二阶段的任务
 busaracleaned
 carlcleaned
 anilcleaned
 第二段任务结束后，再次打印on_completion函数的内容，因为内部是静态字符串，第二次不再执行初始化操作
 直接打印第一次修改后的字符串值
...done
 */


