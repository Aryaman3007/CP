#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &m, int start)
{
    queue<TreeNode *> q;
    TreeNode *target;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr->val == start)
        {
            target = curr;
        }
        if (curr->left)
        {
            m[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            m[curr->right] = curr;
            q.push(curr->right);
        }
    }
    return target;
}

int amountOfTime(TreeNode *root, int start)
{

    unordered_map<TreeNode *, TreeNode *> m;
    TreeNode *temp = markParents(root, m, start);
    queue<TreeNode *> qu;
    qu.push(temp);

    unordered_map<TreeNode *, bool> visited;
    visited[temp] = true;
    int curr_level = 0;

    while (!qu.empty())
    {
        int size = qu.size(), fl = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = qu.front();
            qu.pop();
            visited[node] = true;
            if (node->left && !visited[node->left])
            {
                fl = 1;
                qu.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right])
            {
                fl = 1;
                qu.push(node->right);
                visited[node->right] = true;
            }
            if (m[node] && !visited[m[node]])
            {
                fl = 1;
                qu.push(m[node]);
                visited[m[node]] = true;
            }
        }
        if (fl)
            curr_level++;
    }

    return curr_level;
}