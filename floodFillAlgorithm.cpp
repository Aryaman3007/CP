#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image, vector<vector<int>> &ans, int sr, int sc, int color, int inicolor, int delrow[], int delcol[])
{
    ans[sr][sc] = color;
    int n = ans.size();
    int m = ans[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = sr + delrow[i];
        int ncol = sc + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != color)
        {
            dfs(image, ans, nrow, ncol, color, inicolor, delrow, delcol);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    //SC-> O(NxM)->ans matrix + O(NxM)->recursion stackspace
    //TC-> O(NxM)->for reaching every node if have same inicolor + O(4xNxM)->for reaching neighbours of every node ~ O(NxM);
    int inicolor = image[sr][sc];
    vector<vector<int>> ans = image;
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0, +1};
    dfs(image, ans, sr, sc, color, inicolor, delrow, delcol);
    return ans;
}