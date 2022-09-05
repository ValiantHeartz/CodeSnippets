#include <bits/stdc++.h> 
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x){}
};

ListNode* makeList(vector<int>& nums){
    ListNode* head = new ListNode(nums[0]);
    ListNode* temp = head;
    for(int i = 1; i < nums.size(); ++i){
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> vec{1,2,3,4,5};
    ListNode* head = makeList(vec);
    cout<<head->next->val;
}