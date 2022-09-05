#include <bits/stdc++.h> 
using namespace std;
// 适配器模式：组合和继承
// 1、继承
class mystack: private deque<int>
{
    public:
        mystack(){};
        void push(int x){
            push_front(x);
        }
        int top(){
            return front();
        }
};

// 2、组合
class mystack
{
    private:
        deque<int> dq;
    public:
        mystack(){};
        void push(int x){
            dq.push_front(x);
        }
        int top(){
            return dq.front();
        }
};
int main(){
    mystack a;
    a.push(2);
    cout<<a.top();
}