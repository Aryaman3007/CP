#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    m[0] = 1;
    int preSum = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        preSum += nums[i];
        cnt += m[preSum - k];
        m[preSum]++;
    }
    return cnt;
}