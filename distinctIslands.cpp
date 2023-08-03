#include <bits/stdc++.h>
using namespace std;

void dfs(int row0, int col0, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &temp, int r, int c)
{
    vis[r][c] = 1;
    temp.push_back(make_pair(r - row0, c - col0));
    int n = grid.size();
    int m = grid[0].size();
    int delrow[] = {-1, 0, 0, 1};
    int delcol[] = {0, 1, -1, 0};
    for (int i = 0; i < 4; i++)
    {
        int nrow = r + delrow[i];
        int ncol = c + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(row0, col0, grid, vis, temp, nrow, ncol);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> temp;
                dfs(i, j, grid, vis, temp, i, j);
                ans.insert(temp);
            }
        }
    }
    return ans.size();
}