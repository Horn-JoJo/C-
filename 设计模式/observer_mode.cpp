#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Subject;//类的声明！！！

//观察者基类
class Observer {
protected:
    string name;//观察者的名字
    Subject* sub;//被观察者

public:
    //构造函数：初始化 姓名和被观察者对象
    Observer(string name, Subject* sub) {
        this->name = name;
        this->sub = sub;//构造函数来实例化sub
    }
    virtual void update() = 0;//虚函数，留给子类实现
};

//子类：股票观察者（摸鱼）
class StockObserver: public Observer {
public:
    //子类构造方法继承父类的实现逻辑
    StockObserver(string name, Subject* sub) : Observer(name, sub) {

    }
    void update();//放到类外实现
};

//子类：NBA观察者(摸鱼)
class NBAObserver: public Observer {
public:
    NBAObserver(string name, Subject* sub) : Observer(name, sub) {

    }
    void update();//放到类外实现
};

//被观察者基类 （内部存了所有的观察者对象，以便状态发生变化时，给观察者发通知）
class Subject {
protected:
    list<Observer*> observers;

public:
    string action;//被观察者对象的动作状态
    virtual void attach(Observer*) = 0;
    virtual void detach(Observer*) = 0;
    virtual void notify() = 0;
};

//被观察者子类
class Secretary: public Subject {
    //添加观察者
    void attach(Observer* observer) {
        observers.push_back(observer);
    }
    
    //删除观察者
    void detach(Observer* observer) {
        list<Observer*>::iterator iter = observers.begin();
        while (iter != observers.end()) {
            if ((*iter) == observer) {
                observers.erase(iter);
                return;
            }
            ++iter;
        }
    }
    
    //被观察者通知观察者：调用观察者的方法
    void notify() {
        list<Observer*>::iterator iter = observers.begin();
        while (iter != observers.end()) {
            (*iter)->update();
            ++iter;
        }
    }

};

void StockObserver::update() {
    cout << name << "收到消息 " << sub->action << endl;
    if (sub->action == "梁所长来了!") {
        cout << "我马上关闭股票，装作很认真的样子!" << endl;
    }
}

void NBAObserver::update() {
    cout << name << "收到消息 " << sub->action << endl;
    if (sub->action == "梁所长来了!") {
        cout << "我马上关闭NBA，装作很认真的样子!" << endl;
    }
}

int main() {
    Subject* dwq = new Secretary();//实例化了一个被观察者所长
    Observer* xs = new NBAObserver("xiaoshuai", dwq);//实例化了一个观察者，并且添加了对应的被观察对象
    Observer* zy = new NBAObserver("zouyue", dwq);//同上
    Observer* lm = new StockObserver("limin", dwq);//同上
    
    //所长添加
    dwq->attach(xs);
    dwq->attach(zy);
    dwq->attach(lm);

    dwq->action = "去吃饭了!";
    dwq->notify();
    cout << endl;

    dwq->action = "梁所长来了!";
    dwq->notify();

    return 0;
}
