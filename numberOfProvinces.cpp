#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &visited, vector<int> adj[])
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, visited, adj);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    //SC -> O(2N) 
    //Tc -> O(N) + O(2E + N)
    int n = isConnected[0].size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && isConnected[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> visited(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i, visited, adj);
        }
    }
    return cnt;
}