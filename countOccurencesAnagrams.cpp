#include <bits/stdc++.h>
using namespace std;

int search(string pat, string txt)
{
    // Sliding Window
    unordered_map<char, int> um;
    int k = pat.size();
    for (auto it : pat)
    {
        um[it]++;
    }
    int cnt = um.size();
    int st = 0, end = 0;
    int ans = 0;
    while (end < txt.size())
    {
        if (um.find(txt[end]) != um.end())
        {
            um[txt[end]]--;
            if (um[txt[end]] == 0)
            {
                cnt--;
            }
        }
        if (end - st + 1 < k)
        {
            end++;
        }
        else if (end - st + 1 == k)
        {
            if (cnt == 0)
            {
                ans++;
            }
            if (um.find(txt[st]) != um.end())
            {
                um[txt[st]]++;
                if (um[txt[st]] == 1)
                {
                    cnt++;
                }
            }
            st++;
            end++;
        }
    }
    return ans;
}