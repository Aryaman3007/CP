#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &days,vector<int> &costs,int ind,int n,vector<int> &dp){
    if(ind>=n) return 0;
    if(dp[ind]!=-1) return dp[ind];

    //1-day pass
    int option1=costs[0] + solve(days,costs,ind+1,n,dp);

    //7-days pass
    int i;
    for(i=ind;i<n && days[i]<days[ind]+7;i++);
    int option2 = costs[1] + solve(days,costs,i,n,dp);

    //30-days pass
    int j;
    for(j=ind;j<n && days[j]<days[ind]+30;j++);
    int option3 = costs[2] + solve(days,costs,j,n,dp);
    
    return dp[ind]=min({option1,option2,option3});
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n=days.size();
    vector<int> dp(n,-1);
    return solve(days,costs,0,n,dp);                
}