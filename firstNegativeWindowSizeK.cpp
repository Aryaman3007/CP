#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    vector<long long> ans;
    long long st = 0, end = 0;
    queue<long long> q;
    while (end < N)
    {
        if (A[end] < 0)
        {
            q.push(A[end]);
        }
        if (end - st + 1 < K)
            end++;
        else if (end - st + 1 == K)
        {
            if (q.empty())
                ans.push_back(0);
            else
                ans.push_back(q.front());

            if (q.front() == A[st])
                q.pop();

            st++;
            end++;
        }
    }
    return ans;
}