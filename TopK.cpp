#include <bits/stdc++.h> 
using namespace std;
void adjust(vector<int> &nums){
    int len = nums.size();
    for(int i = 0; i < len/2+1;++i){
        int father = i, son = 2*i+1;
        if(2*i+2 < len && nums[2*i+1] > nums[2*i+2]){
            son = 2*i+2;
        }
        if(son < len && nums[father] > nums[son]){
            swap(nums[father], nums[son]);
        }
    }
}
int main(){
    vector<int> nums{2,1,5,4,6,3,7,9,8,10};
    int k = 1;
    vector<int> res(k,0);
    for(int i = 0; i < k; ++i) res[i] = nums[i];
    adjust(res);
    for(int i = k; i < nums.size(); ++i){
        if(nums[i] > res[0]){
            res[0] = nums[i];
            adjust(res);
        }
    }
    for(auto i : res) cout<<i<<',';
}
