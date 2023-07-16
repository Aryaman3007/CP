#include <bits/stdc++.h>
using namespace std;

vector<int> nearlySorted(vector<int> &arr, int num, int K)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;  //min heap
    for (int i = 0; i < num; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > K)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}