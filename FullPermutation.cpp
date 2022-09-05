#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> res;
vector<vector<int>> permute(vector<int>& nums) {
	helper(nums,0);
	return res;
}

void helper(vector<int>& nums, int start){
	if(start == nums.size() - 1){
		res.push_back(nums);
		return;
	}
	for(int i = start; i < nums.size();++i){
		swap(nums[i], nums[start]);
		helper(nums, start+1);
		swap(nums[i], nums[start]);
	}
}