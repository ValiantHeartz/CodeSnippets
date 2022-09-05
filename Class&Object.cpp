#include <bits/stdc++.h> 
using namespace std;

class object1{   
public:
    static int d;
    object1(){
        cout<<"object1"<<endl;
    }
    object1(int a){
        cout<<a<<endl;
    }
    ~object1(){
        cout<<"~object1"<<endl;
    }
    static void printt(){
        cout<<d;
    }
    int test(int e){
        static int b = 0;
        if(e>6) b = e;
        int c = 3;
        return b;
    }
    void e(){
        cout<<1;
    }
};

class o2{
    virtual void a(){
        cout<<1;
    }
};
class o3 : public o2{
    virtual void b(){
        cout<<2;
    }
};
class o4 : public o2{
    virtual void c(){
        cout<<2;
    }
    
};
class o5 : public object1{
public:
    o5(){
        cout<<"o5make"<<endl;
    }
    void e(){
        cout<<5;
    }
    ~o5(){
        cout<<"o5delete"<<endl;
    }
};
int object1::d = 4;
int main(){
    object1 *os = new o5();
    os->e();
}