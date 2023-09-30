#include <cstdlib>
#include <functional>
#include <iostream>
#include <random>
using namespace std;

int main() {
#ifdef D1
    cout << "离散型随机分布" << endl;
    std::uniform_int_distribution<int> distribution(0, 99);//离散型随机分布
    std::mt19937 engine;//随机数生成引擎
    auto generator = std::bind(distribution, engine);//将随机数生成和对应的分布绑定并生成函数
#endif    

#ifdef D2
    cout << "伯努利分布" << endl;
    std::bernoulli_distribution<int> distribution1(0, 99);
    std::mt19937 engine1;//随机数生成引擎
    auto generator = std::bind(distribution1, engine1);
#endif

#ifdef D3
    cout << "几何分布" << endl;
    std::geometric_distribution<int> distribution2(0, 99);
    std::mt19937 engine2;//随机数生成引擎
    auto generator = std::bind(distribution2, engine2);
#endif

#ifdef D4
    cout << "二项分布" << endl;
    std::poisson_distribution<int> distribution3(0, 99);
    std::mt19937 engine3;//随机数生成引擎
    auto generator = std::bind(distribution3, engine3);
#endif

    int random = generator();//产生随机数
    cout << random << endl;

    return 0;
}
