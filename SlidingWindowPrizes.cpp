#include<bits/stdc++.h>
using namespace std;

int maximizeWin(vector<int> &prizePositions, int k)
{
    int n = prizePositions.size();
    int j = 0;
    int ans = 0;
    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        while ((prizePositions[i] - prizePositions[j]) > k)
            j++;
        sum[i + 1] = max(sum[i], i - j + 1);
        ans = max(ans, i - j + 1 + sum[j]);
    }
    return ans;
}
