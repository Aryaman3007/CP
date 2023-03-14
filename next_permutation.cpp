#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int k=n-2;
        while(k>=0){       
            if(nums[k]<nums[k+1]){
                break;
            }
            k--;
        }   

        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            int t=n-1;
            while(t>k){
                if(nums[t]>nums[k]) break;
                t--;
            }
            swap(nums[k],nums[t]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};