#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &vis, vector<vector<char>> &board, int row, int col, int delrow[], int delcol[])
{
    vis[row][col] = 1;
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
            !vis[nrow][ncol] && board[nrow][ncol] == 'O')
        {
            dfs(vis, board, nrow, ncol, delrow, delcol);
        }
    }
}

void solve(vector<vector<char>> &board)
{
    //TC-> O(N*M*4) + O(N) ~ O(N*M)
    //SC-> O(N*M) for visited and auxiliary stack space
    int m = board.size();
    int n = board[0].size();
    int delrow[] = {-1, 0, 0, 1};
    int delcol[] = {0, -1, 1, 0};
    vector<vector<int>> vis(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        if (!vis[i][0] && board[i][0] == 'O')
        {
            dfs(vis, board, i, 0, delrow, delcol);
        }
        if (!vis[i][n - 1] && board[i][n - 1] == 'O')
        {
            dfs(vis, board, i, n - 1, delrow, delcol);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[0][i] && board[0][i] == 'O')
        {
            dfs(vis, board, 0, i, delrow, delcol);
        }
        if (!vis[m - 1][i] && board[m - 1][i] == 'O')
        {
            dfs(vis, board, m - 1, i, delrow, delcol);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0 && board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}