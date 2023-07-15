#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int profit = 0;
    int mini = prices[0];
    int cost;
    for (int i = 1; i < n; i++)
    {
        cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, prices[i]);
    }
    return profit;
}

int main(){
    vector<int> prices={7,1,5,3,6,4};
    cout<<maxProfit(prices);
    return 0;
}