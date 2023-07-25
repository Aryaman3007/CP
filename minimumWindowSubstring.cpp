#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    unordered_map<char, int> mp;
    for (auto it : t)
    {
        mp[it]++;
    }
    int cnt = mp.size();
    int st = 0, end = 0;
    int start = 0;
    int minlen = INT_MAX;
    while (end < s.size())
    {
        if (mp.find(s[end]) != mp.end())
        {
            mp[s[end]]--;
            if (mp[s[end]] == 0)
            {
                cnt--;
            }
        }
        if (cnt == 0)
        {
            while (cnt == 0)
            {
                if (mp.find(s[st]) != mp.end())
                {
                    mp[s[st]]++;
                    if (mp[s[st]] == 1)
                    {
                        cnt++;
                    }
                    if (end - st + 1 < minlen)
                    {
                        minlen = end - st + 1;
                        start = st;
                    }
                }
                st++;
            }
        }
        end++;
    }
    if (minlen == INT_MAX)
        return "";
    return s.substr(start, minlen);
}