#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(TreeNode *root)
{
    if (root == NULL)  return 0;
    int lefth = maxDepth(root->left);
    int righth = maxDepth(root->right);
    if (lefth == -1 || righth == -1)
        return -1;
    if (abs(lefth - righth) > 1)
        return -1;
    return 1 + max(lefth, righth);
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL)
        return true;
    int ans = maxDepth(root);
    if (ans == -1)
        return false;
    return true;
}