#include <bits/stdc++.h> 
using namespace std;

int main(){
    srand((unsigned)time(0));
    for(int i = 10; i >= 0; --i)
    cout<<rand()%3<<',';
    cout<<time(0);
}