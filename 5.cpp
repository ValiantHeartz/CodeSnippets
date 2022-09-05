#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    for(int i = 0; i < t; ++i){
        int n;cin>>n;
        vector<int> vec(n,0);
        for(int j = 0; j < n; ++j){
            int temp;cin>>temp;
            vec[i] = temp;
        }
        int flagno = 0;
        for(int j = 0; j < n; ++j){
            for(int k = j+1; k < n; ++k){
                for(int o = k+1; o < n; ++o){
                    int flag = 1;
                    for(int p = 0; p < n && p!=j&&p!=k&&p!=o;++p){

                        if(vec[j]+vec[k]+vec[o] == vec[p]){
                            flag = 0;//cout<<"NO"<<endl
                            break;
                        }
                    }
                    if(flag){
                        flagno = 1;
                        //cout<<"NO"<<endl;
                        break;
                    }
                }
            }
        }
        if(!flagno) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}