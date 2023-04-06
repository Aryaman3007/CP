#include <bits/stdc++.h>
using namespace std;
int getLongestSubarray(vector<int> &nums, int k)
{
    long long preSum = 0;
    int maxLen = 0;
    map<long long, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        preSum += nums[i];
        if (preSum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        long long remove = preSum - k;
        if (m.find(remove) != m.end())
        {
            maxLen = max(maxLen, i - m[remove]);
        }
        if (m.find(preSum) == m.end())
        {
            m[preSum] = i;
        }
    }
    return maxLen;
}