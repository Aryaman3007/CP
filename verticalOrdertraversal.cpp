#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> node;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        TreeNode *it = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;
        node[x][y].insert(it->val);
        if (it->left)
        {
            q.push({it->left, {x - 1, y + 1}});
        }
        if (it->right)
        {
            q.push({it->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto c : node)
    {
        vector<int> col;
        for (auto d : c.second)
        {
            col.insert(col.end(), d.second.begin(), d.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}