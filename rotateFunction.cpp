#include<bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& nums) {
    int n=nums.size();
    if(n==1){
        return 0;
    }
    int ans=0;
    int temp=0;
    for(int i=0;i<n;i++){
        ans+= nums[i];
        temp+= i*nums[i];
    } 
    int res=temp;
    for(int i=n-1;i>0;i--){
        temp=temp+ans-(n* nums[i]);
        res=max(temp,res);
    }   
    return res;
}
