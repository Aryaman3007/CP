#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    set<vector<int>> s;
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int front = j + 1;
            int back = nums.size() - 1;
            while (front < back)
            {
                long long int sum = nums[i];
                sum += nums[j];
                sum += nums[front];
                sum += nums[back];

                if (sum == target)
                {
                    s.insert({nums[i], nums[j], nums[front], nums[back]});
                    front++;
                    back--;
                }
                else if (sum < target)
                {
                    front++;
                }
                else
                {
                    back--;
                }
            }
        }
    }
    for (auto i : s)
        ans.push_back(i);
    return ans;
}