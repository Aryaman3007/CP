#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> arr, int n, long long s)
{
    int start = 0;
    long long sum = arr[0];
    for (int i = 1; i <= arr.size(); i++)
    {
        while (sum > s && start < i - 1)
        {
            sum = sum - arr[start];
            start++;
        }
        if (sum == s)
        {
            return {start + 1, i};
        }
        if (i < n)
            sum += arr[i];
    }
    return {-1};
}