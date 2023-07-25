#include <iostream>
#include <vector>
#include<queue>
using namespace std;

void bfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int n, int m, int r, int c)
{
    visited[r][c] = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse to its neighbours and mark them as land
        for (int i = -1; i <= 1; i++)
        {
            int newr = row + i;
            int newc = col + i;

            if (newr >= 0 && newr < n && !visited[newr][col] && grid[newr][col] == '1') //check adjacent rows
            {
                visited[newr][col] = 1;
                q.push({newr, col});
            }
            if (newc >= 0 && newc < m && !visited[row][newc] && grid[row][newc] == '1') //check adjacent columns
            {
                visited[row][newc] = 1;
                q.push({row, newc});
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    //SC -> O(N^2) + O(N^2)
    //TC -> O(N^2)*8 ~= O(N^2)
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {
                ans++;
                bfs(grid, visited, n, m, i, j);
            }
        }
    }
    return ans;
}
