#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    string ans = "";
    for (int i = 0; i < strs[0].length(); i++)
    {
        char ch = strs[0][i];
        for (int j = 1; j < n; j++)
        {
            if (i >= strs[j].length() || ch != strs[j][i])
            {
                return ans; // Return the current ans if a mismatch is found
            }
        }
        ans += ch; // Add the character to the common prefix
    }
    return ans;
}