#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
};

void inorder(TreeNode *root, vector<int> &nums)
{
    if (root != NULL)
    {
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
}

int kthSmallest(TreeNode *root, int k)
{
    vector<int> nums;
    inorder(root, nums);
    int n = nums.size();
    return nums[k - 1];
}