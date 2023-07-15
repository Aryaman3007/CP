#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;  //min heap
    for (int i = 0; i < nums.size(); i++)
    {
        minh.push(nums[i]);
        if (minh.size() > k)
        {
            minh.pop();
        }
    }
    return minh.top();
}