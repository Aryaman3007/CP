#include <bits/stdc++.h>
using namespace std;

vector<int> toposort(vector<int> adj[], int k)
{
    int vis[k] = {0};
    vector<int> ans;
    queue<int> q;
    vector<int> indegree(k, 0);
    for (int i = 0; i < k; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
        ans.push_back(node);
    }
    return ans;
}

string findOrder(string dict[], int N, int K)
{
    // code here
    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());
        for (int i = 0; i < len; i++)
        {
            if (s1[i] != s2[i])
            {
                adj[s1[i] - 'a'].push_back(s2[i] - 'a');
                break;
            }
        }
    }

    vector<int> res = toposort(adj, K);
    string s = "";
    for (auto it : res)
    {
        s += char(it + 'a');
    }
    return s;
}