#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <string>
#include <mutex>

using namespace std;

//将一个任务分成若干个小任务去执行，每个小任务用新的线程来处理！！！
template <typename RandomIt>
int parallel_sum(RandomIt beg, RandomIt end) {
    auto len = end - beg;
    if (len < 1000) 
        return std::accumulate(beg, end, 0);//当规模小于1000时，就去累加该区间的部分和

    RandomIt mid = beg + len / 2;
    auto handle = std::async(std::launch::async,
                             parallel_sum<RandomIt>, mid, end);//当规模大于1000时，则划分一半开启一个新的线程来处理，如果还是大于1000，则新线程又会创建新的线程来处理
    int sum = parallel_sum(beg, mid);//计算开始到中间的一半规模的求和。如果规模还是很大，还会创建新的线程来计算较小的和！！！
    return sum + handle.get();
}

//同上代码逻辑！！！ 递归+多线程！！！
template <typename RandomIt>
int parallel_min(RandomIt beg, RandomIt end) {
    auto len = end - beg;
    if (len < 1000) 
        return *(std::min_element(beg, end));

    RandomIt mid = beg + len / 2;
    auto handle = std::async(std::launch::async,
                             parallel_min<RandomIt>, mid, end);
    int ans = parallel_min(beg, mid);
    return std::min(ans, handle.get());
}

int main() {
    std::vector<int> v(10000);
    iota(v.begin(), v.end(), 1);
    std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << std::endl;
    std::cout << "The min elemnet is " << parallel_min(v.begin(), v.end()) << std::endl;
    return 0;
}
