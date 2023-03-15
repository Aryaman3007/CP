#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int> &nums,int T,int ind,vector<vector<int>> &dp){
    if(ind==0){
        if(T%nums[ind]==0) return T/nums[ind];
        return 1e9;
    }

    if(dp[ind][T]!=-1) return dp[ind][T];

    int notTake=0+ solve(nums,T,ind-1,dp);
    int take=INT_MAX;
    if(nums[ind]<=T){
        take=1+solve(nums,T-nums[ind],ind,dp);
    }
    return dp[ind][T]=min(take,notTake);
}

int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int> (x+1,-1));
    int ans=solve(num,x,n-1,dp);
    if(ans>=1e9) return -1;
    return solve(num,x,n-1,dp);
}