#include <bits/stdc++.h>
using namespace std;

static bool compare(vector<int> &v1, vector<int> &v2)
{
    return v1[1] < v2[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), compare);
    int prev = intervals[0][1];
    int cnt = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] < prev)
        {
            cnt++;
        }
        else
        {
            prev = intervals[i][1];
        }
    }
    return cnt;
}