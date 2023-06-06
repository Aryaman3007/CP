#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *searchBST(TreeNode *root, int val)
{
    while (root != NULL && root->val != val)
    {
        root = (root->val > val) ? root->left : root = root->right;
    }
    return root;
}