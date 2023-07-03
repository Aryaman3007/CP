#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
};

bool solve(TreeNode *root, long low, long high)
{
    if (root == NULL)
        return true;
    if (root->val <= low || root->val >= high)
        return false;
    return solve(root->left, low, root->val) && solve(root->right, root->val, high);
}

bool isValidBST(TreeNode *root)
{
    return solve(root, LONG_MIN, LONG_MAX);
}