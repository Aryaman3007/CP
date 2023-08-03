#include <bits/stdc++.h>
using namespace std;

bool bfs(int start, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool dfs(int start, int col, vector<vector<int>> &graph, vector<int> &color)
{
    color[start] = col;
    for (auto it : graph[start])
    {
        if (color[it] == -1)
        {
            if (dfs(it, !col, graph, color) == false)
                return false;
        }
        else if (color[it] == col)
            return false;
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    // TC-> O(N +2E)*N
    // SC-> O(N)
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (bfs(i, adj, color) == false)
                return false;
        }
    }
    return true;
}