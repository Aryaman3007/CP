#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    int st = 0, end = 0;
    deque<int> dq;
    int maxi = INT_MIN;
    while (end < nums.size())
    {
        if (dq.empty())
        {
            dq.push_front(nums[end]);
        }
        else
        {
            while (!dq.empty() && nums[end] > dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(nums[end]);
        }

        if (end - st + 1 < k)
            end++;
        else if (end - st + 1 == k)
        {
            ans.push_back(dq.front());
            if (dq.front() == nums[st])
            {
                dq.pop_front();
            }
            st++;
            end++;
        }
    }
    return ans;
}