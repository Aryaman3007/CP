#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> ans;
    int s = 0;
    int e = numbers.size() - 1;
    int a = 0, b = 0;
    while (s < e)
    {
        if (numbers[s] + numbers[e] == target)
        {
            a = s + 1;
            b = e + 1;
            break;
        }
        else if (numbers[s] + numbers[e] > target)
        {
            e--;
        }
        else
        {
            s++;
        }
    }
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}