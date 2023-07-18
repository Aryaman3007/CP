#include <bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int K, vector<int> &Arr, int N)
{
    // Sliding Window
    long sum = 0;
    long ans = LONG_MIN;
    long st = 0, end = 0;
    while (end < N)
    {
        sum += Arr[end];
        if (end - st + 1 < K)
        {
            end++;
        }
        else if (end - st + 1 == K)
        {
            ans = max(ans, sum);
            sum -= Arr[st];
            st++;
            end++;
        }
    }
    return ans;
}