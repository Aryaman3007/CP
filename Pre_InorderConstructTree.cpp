#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd, map<int, int> &m)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;
    TreeNode *root = new TreeNode(preorder[preStart]);
    int inroot = m[root->val];
    int numsleft = inroot - inStart;
    root->left = solve(preorder, inorder, preStart + 1, preStart + numsleft, inStart, inroot - 1, m);
    root->right = solve(preorder, inorder, preStart + numsleft + 1, preEnd, inStart + numsleft + 1, inroot + 1, m);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> inmap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inmap[inorder[i]] = i;
    }
    return solve(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size(), inmap);
}