#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathvis, vector<int> &safenode)
{
    vis[node] = 1;
    pathvis[node] = 1;
    for (auto it : graph[node])
    {
        if (!vis[it])
        {
            if (dfs(it, graph, vis, pathvis, safenode) == true)
                return true;
        }
        // if the node has been previously visited but if it has been in same path?
        else if (pathvis[it])
        {
            return true;
        }
    }
    safenode.push_back(node);
    pathvis[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> safenode;
    vector<int> vis(V, 0);
    vector<int> pathvis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, graph, vis, pathvis, safenode);
        }
    }
    sort(safenode.begin(), safenode.end());
    return safenode;
}
