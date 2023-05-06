#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL || q==NULL) return (p==q);
    return (p->val==q->val 
        && isSameTree(p->left,q->left) 
        && isSameTree(p->right,q->right)
    );     
}