#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    map<int,int> m;
    int i=0;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
    }
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second>=2){
            nums[i++]=it->first;
            nums[i++]=it->first;
            ans+=2;
        }
        else{
            nums[i++]=it->first;
            ans+=it->second;
        }
    }
    return ans;
        
}
