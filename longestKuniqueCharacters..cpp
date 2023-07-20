#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k)
{
    // Sliding window
    unordered_map<char, int> mp;
    int st = 0, end = 0;
    int ans = 0;
    while (end < s.size())
    {
        mp[s[end]]++;
        if (mp.size() < k)
        {
        }
        else if (mp.size() == k)
        {
            ans = max(ans, end - st + 1);
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[st]]--;
                if (mp[s[st]] == 0)
                {
                    mp.erase(s[st]);
                }
                st++;
            }
        }
        end++;
    }
    if (ans < k)
        return -1;
    return ans;
}