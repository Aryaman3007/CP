#include <bits/stdc++.h> 
using namespace std;

int solve(int ind,int W,vector<int> &wt,vector<int> &val,vector<vector<int>> &dp){
	if(ind==0){
		if(wt[0]<=W) return val[ind];
		else return 0;
	}
	if(dp[ind][W]!=-1) return dp[ind][W];
	int notTake=0+solve(ind-1,W,wt,val,dp);
	int Take=INT_MIN;
	if(wt[ind]<=W) Take=val[ind] + solve(ind-1,W-wt[ind],wt,val,dp);
	return dp[ind][W]=max(notTake,Take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int> (maxWeight+1,-1));
	return solve(n-1,maxWeight,weight,value,dp);
}