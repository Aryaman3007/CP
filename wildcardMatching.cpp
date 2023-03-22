#include <bits/stdc++.h>
using namespace std;

bool solve(string &s, string &p, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 == 0 && ind2 == 0)
    {
        return true;
    }

    if (ind1 == 0)
    {
        for (int k = 0; k < ind2; k++)
            if (p[k] != '*')
                return false;
        return true;
    }

    if (ind2 == 0 && ind1 != 0)
        return false;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s[ind1 - 1] == p[ind2 - 1] || p[ind2 - 1] == '?')
    {
        return dp[ind1][ind2] = solve(s, p, ind1 - 1, ind2 - 1, dp);
    }

    if (p[ind2 - 1] == '*')
    {
        return dp[ind1][ind2] = (solve(s, p, ind1 - 1, ind2, dp) || solve(s, p, ind1, ind2 - 1, dp));
    }
    return dp[ind1][ind2] = false;
}

bool isMatch(string s, string p)
{
    int l1 = s.size();
    int l2 = p.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));
    return solve(s, p, l1, l2, dp);
}