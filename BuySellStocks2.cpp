#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, vector<vector<int>> &dp, int ind, int buy)
{
    if (ind == prices.size())
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    int profit;
    if (buy)
    {
        profit = max(-prices[ind] + solve(prices, dp, ind + 1, 0), 0 + solve(prices, dp, ind + 1, 1));
    }
    else
    {
        profit = max(prices[ind] + solve(prices, dp, ind + 1, 1), 0 + solve(prices, dp, ind + 1, 0));
    }
    return dp[ind][buy] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // vector<vector<int>> dp(n, vector<int> (2,-1));  -->Memoization
    // return solve(prices,dp,0,1);

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));  //-->Tabulation
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    { // traversing for every prices
        for (int j = 0; j < 2; j++)
        { // if at i we can buy or not (0 or 1)
            int profit;
            if (j)
            {
                profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
            }
            else
            {
                profit = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
            }
            dp[i][j] = profit;
        }
    }
    return dp[0][1];
}

int main(){
    vector<int> prices={7,1,5,3,6,4};
    cout<<maxProfit(prices);
    return 0;
}