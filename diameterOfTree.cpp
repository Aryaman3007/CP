#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

int solve(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int lh = solve(root->left, maxi);
    int rh = solve(root->right, maxi);
    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int ans = 0;
    solve(root, ans);
    return ans;
}