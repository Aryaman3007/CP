#include <iostream>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // TC-> O(V) + O(2E)-->total degree
    // SC-> 0(3N)
    vector<int> ans;
    int visited[V] = {0};
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int t = q.front();
        ans.push_back(t);
        q.pop();
        for (auto it : adj[t])
        {
            if (visited[it] == 0)
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    return ans;
}