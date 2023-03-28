struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULLptr), right(NULLptr) {}
    TreeNode(int x) : val(x), left(NULLptr), right(NULLptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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