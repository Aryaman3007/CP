#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void solve(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    solve(root->left, ans);
    ans.push_back(root->val);
    solve(root->right, ans);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> v;
    // solve(root,v);
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            v.push_back(node->val);
            node = node->right;
        }
    }
    return v;
}
