#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>

//创建二元信号量smphSignalMainToThread和smphSignalThreadToMain 初值均为0
// 需要指定编译器版本！！！ g++ -std=c++2a semphore.cpp && ./a.out ！！！
std::binary_semaphore smphSignalMainToThread{0}, smphSignalThreadToMain{0};
 
//线程函数
void ThreadProc()
{	
    // 第一次进入阻塞
	smphSignalMainToThread.acquire();//这里初始值均为0，因此减不动，就等待 需要其他线程先加
    //类似于wait操作 wait  p:-1  v+1 post
	std::cout << "[thread] Got the signal\n"; // response message
	using namespace std::literals;
	std::this_thread::sleep_for(3s);
	std::cout << "[thread] Send the signal\n"; // message
    // 唤醒 main 线程
	smphSignalThreadToMain.release();//类似于notify
}
 
int main()
{
    //创建线程
	std::thread thrWorker(ThreadProc);
	std::cout << "[main] Send the signal\n"; // message
    // 唤醒 ThreadProc 先加1操作！
	smphSignalMainToThread.release();
    // main 线程阻塞 因为初始该信号量为0 减不动，这时只有子线程执行+1操作后这里才会继续执行
	smphSignalThreadToMain.acquire();
	std::cout << "[main] Got the signal\n"; // response message
	thrWorker.join();
}
/*
[main] Send the signal
[thread] Got the signal
等待3s后
[thread] Send the signal
[main] Got the signal
*/

