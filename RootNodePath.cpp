#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool path(TreeNode* root,int a,vector<int> &ans){
    if(!root) return false;
    ans.push_back(root->val);
    if(root->val==a) return true;
    if(path(root->left,a,ans) || path(root->right,a,ans)) return true;
    ans.pop_back();
    return false;
}

vector<int> solve(TreeNode* root,int a){
    vector<int> ans;
    if(root==NULL) return ans;
    path(root,a,ans);
    return ans;
}