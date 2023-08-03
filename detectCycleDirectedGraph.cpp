#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathvis)
{
    vis[node] = 1;
    pathvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, adj, vis, pathvis) == true)
                return true;
        }
        // if the node has been previously visited but if it has been in same path?
        else if (pathvis[it])
        {
            return true;
        }
    }
    pathvis[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // TC -> O(V + E)
    // SC -> O(N) + O(N)
    vector<int> vis(V, 0);
    vector<int> pathvis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathvis) == true)
                return true;
        }
    }
    return false;
}