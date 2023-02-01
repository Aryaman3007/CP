#include<bits/stdc++.h>
using namespace std;

int frog(int ind,vector<int> &height){
    if(ind==0) return 0;
    int prev1=0;
    int prev2=0;
    for(int i=1;i<height.size();i++){
        int jump2=INT_MAX;
        int jump1=prev1 + abs(height[i] - height[i-1]);
        if(i>1) jump2=prev2 + abs(height[i] - height[i-2]);
        int curr=min(jump1,jump2);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main(){
    int n;cin>>n;
    vector<int> v;
    vector<int> height;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        height.push_back(x);
    }
    cout<<frog(n-1,height);
}