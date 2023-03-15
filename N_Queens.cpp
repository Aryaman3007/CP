#include <bits/stdc++.h>
using namespace std;

bool issafe(int row, int col, vector<string> board, int n)
{

    int r = row;
    int c = col;
    while (c >= 0)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
        c--;
    }

    int r1 = row;
    int c1 = col;
    while (r1 >= 0 && c1 >= 0)
    {
        if (board[r1][c1] == 'Q')
        {
            return false;
        }
        r1--;
        c1--;
    }

    int r2 = row;
    int c2 = col;
    while (r2 < n && c2 >= 0)
    {
        if (board[r2][c2] == 'Q')
        {
            return false;
        }
        r2++;
        c2--;
    }

    return true;
}

void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (issafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, ans, board, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    string s(n, '.');
    vector<string> board(n);
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0, ans, board, n);
    return ans;
}