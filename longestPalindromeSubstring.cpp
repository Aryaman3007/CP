#include <bits/stdc++.h>
using namespace std;

int solve(string &s, int l, int r)
{
    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
        l--;
        r++;
    }
    return r - l - 1;
}

string longestPalindrome(string s)
{
    if (s.size() == 1)
        return s;
    int start = 0;
    int end = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int l1 = solve(s, i, i);
        int l2 = solve(s, i, i + 1);
        int len = max(l1, l2);
        if (len > end - start)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}
