#include<bits/stdc++.h>
using namespace std;

int frogK(int ind,vector<int> &dp,vector<int> &v,int k){
  if(ind==0) return 0;
  if(dp[ind]!=-1) return dp[ind];
  int minsteps=INT_MAX;
  for(int j=1;j<=k;j++){
    if(ind-j>=0){
      int jmp=frogK(ind-j,dp,v,k) + abs(v[ind]-v[ind-j]);
      minsteps=min(minsteps,jmp);
    }
  }
  return dp[ind]=minsteps;
}

int solve(int n,vector<int> &v,int k){
    vector<int> dp(n,-1);
    return frogK(n-1,dp,v,k);
}

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> v;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    v.push_back(x);
  }
  cout<<solve(n,v,k);
  return 0;
}
  
