#include <bits/stdc++.h> 
using namespace std;

class Base{
public:
    double a,b;
    virtual double operation() = 0;
};

class OperationAdd: public Base{
public:
    double operation(){
        return a+b;
    }
};

class OperationMinus:public Base{
    double operation(){
        return a-b;
    }
};

class OperationMul:public Base{
    double operation(){
        return a*b;
    }
};

class OperationDiv:public Base{
    double operation(){
        return a/b;
    }
};

class Factory{
public:
    Base *getOperation(char c){
        switch(c){
            case '+':
                return new OperationAdd();
            case '-':
                return new OperationMinus();
            case '*':
                return new OperationMul();
            case '/':
                return new OperationDiv();
            default:
                return nullptr;
        }
        //return nullptr;
    }
};
int main()
{
   Factory calcF;
   Base* calc = calcF.getOperation('/');
   calc->a = 2;
   calc->b = 3;
   cout<<calc->operation();
} 