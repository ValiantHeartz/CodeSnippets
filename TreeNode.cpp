#include "bits/stdc++.h"
using namespace std; 
struct TreeNode{ 
    int val; 
    TreeNode* left,*right; 
    TreeNode(int n):val(n),left(nullptr),right(nullptr){}
};

// TreeNode* vec2Tree(vector<string> &vec){
//     int len = vec.size();
//     if(len == 0) return nullptr;
//     queue<TreeNode*> que;
//     TreeNode* root = new TreeNode(stoi(vec[0]));
//     que.push(root);
//     int i = 1;
//     while(i<len){
//         TreeNode* temp = que.front();que.pop();
//         if(temp==nullptr){
//             i+=2;continue;
//         }
//         temp->left = vec[i] == "null" ? nullptr : new TreeNode(stoi(vec[i]));
//         que.push(temp->left);
//         if(++i >= len) break;
//         temp->right = vec[i] == "null" ? nullptr : new TreeNode(stoi(vec[i]));
//         que.push(temp->right);
//         ++i;
//     }
//     return root;
// }
void makeTree(TreeNode* root, vector<string>& numstr){
    int len = numstr.size();
    if(!len || numstr[0] == "#") return;
    root->val = stoi(numstr[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(!que.empty() && i < len){
        TreeNode* temp = que.front(); que.pop();
        if(temp){
            temp->left = numstr[i] == "#" ? nullptr : new TreeNode(stoi(numstr[i]));
            i++;
            if(temp->left) que.push(temp->left);
            if(i<len){
                temp->right = numstr[i] == "#" ? nullptr : new TreeNode(stoi(numstr[i]));
                i++;
                if(temp->right) que.push(temp->right);
            }
        }
        else {
            //i+=2;
            continue; //无父节点省略##
        }
    }
}
void printTree(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();que.pop();
        if(temp){
            cout<<temp->val<<',';
            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);
        }
        
    }
    cout<<endl;
}

TreeNode* create(vector<string> vec){
    vector<TreeNode*> treelist;
    for(int i = 0; i < vec.size(); ++i){
        TreeNode* temp;
        if(vec[i] != "null") temp = new TreeNode(stoi(vec[i]));
        else temp = nullptr;
        treelist.push_back(temp);
    }
    int len = vec.size()/2;
    for(int i = 0; i < len; ++i){
        treelist[i]->left = treelist[i*2 + 1];
        treelist[i]->right = treelist[i*2 + 2];
    }
    return treelist[0];
}
int main(){ 
    vector<string> vec={"2","4","5","7","null","null","null","null","3"};
    TreeNode* root = create(vec); //vec2Tree(vec);
    printTree(root);
}