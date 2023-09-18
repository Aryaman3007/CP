#include <bits/stdc++.h>
using namespace std;

// TC O(E x logV) --> O(n*m x logV) same as Dijkstra's algo where E total edges and V total nodes
int minimumEffortPath(vector<vector<int>> &heights)
{
    int rowsize = heights.size();
    int colsize = heights[0].size();
    vector<vector<int>> adj(rowsize, vector<int>(colsize, INT_MAX));
    adj[0][0] = 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 0});
    int row[] = {1, -1, 0, 0};
    int col[] = {0, 0, 1, -1};
    while (!pq.empty())
    {
        auto currvec = pq.top();
        pq.pop();
        int diff = currvec[0];
        int r = currvec[1];
        int c = currvec[2];

        if (r == rowsize - 1 && c == colsize - 1)
            return diff;
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + row[i];
            int ncol = c + col[i];
            if (nrow >= 0 && nrow < rowsize && ncol >= 0 && ncol < colsize)
            {
                int neweffort = max(abs(heights[r][c] - heights[nrow][ncol]), diff);
                if (neweffort < adj[nrow][ncol])
                {
                    adj[nrow][ncol] = neweffort;
                    pq.push({neweffort, nrow, ncol});
                }
            }
        }
    }
    return 0;
}
