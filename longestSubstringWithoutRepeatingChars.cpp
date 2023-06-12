#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> set;
    int l = 0;
    int r = 0;
    int n = s.size();
    int ans = 0;
    while (l < n && r < n)
    {
        if (set.find(s[r]) == set.end())
        {
            set.insert(s[r++]);
            ans = max(ans, r - l);
        }
        else
        {
            set.erase(s[l++]);
        }
    }
    return ans;
}