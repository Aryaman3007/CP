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
    int leftsum = max(0, solve(root->left, maxi));
    int rightsum = max(0, solve(root->right, maxi));
    maxi = max(maxi, leftsum + rightsum + (root->val));
    return (root->val) + max(leftsum, rightsum);
}

int maxPathSum(TreeNode *root)
{
    int ans = INT_MIN;
    solve(root, ans);
    return ans;
}