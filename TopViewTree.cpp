#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<int> getTopView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<TreeNode*, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *temp = it.first;
        int line = it.second;
        if (m.find(line) == m.end())
            m[line] = temp->val;
        if (temp->left)
            q.push({temp->left, line - 1});
        if (temp->right)
            q.push({temp->right, line + 1});
    }

    for (auto node : m)
    {
        ans.push_back(node.second);
    }
    return ans;
}