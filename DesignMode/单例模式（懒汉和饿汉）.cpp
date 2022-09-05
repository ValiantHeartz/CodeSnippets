#include <bits/stdc++.h>
#include <shared_mutex> 
#include <mutex>
using namespace std;

// 1、线程安全的懒汉模式
// 懒汉：故名思义，不到万不得已就不会去实例化类，也就是说在第一次用到类实例的时候才会去实例化一个对象。
// 在访问量较小，甚至可能不会去访问的情况下，采用懒汉实现，这是以时间换空间
mutex mtx;
class singleton{
    private:
        singleton* mysingleton;
    public:
        singleton(){};
        singleton *getInstance(){
            if(mysingleton == nullptr){
                mtx.lock();
                mysingleton = new singleton();
                mtx.unlock();
            }
            return mysingleton;
        }
};

// 2、线程安全的饿汉模式
// 饿汉：饿了肯定要饥不择食。所以在单例类定义的时候就进行实例化。
// 在访问量比较大，或者可能访问的线程比较多时，采用饿汉实现，可以实现更好的性能。这是以空间换时间
class singleton{
    private:
        singleton* mysingleton;
    public:
        singleton(){};
        singleton *getInstance(){
            return mysingleton;
        }
};

singleton *mysingleton = new singleton();
int main(){
    singleton s;
    s.getInstance();
}