#include<bits/stdc++.h>
using namespace std;

void solve(int index,vector<int> &output,vector<vector<int>> &res,vector<int> &nums){
    if(index>=nums.size()){
        res.push_back(output);
        return;
    }
    
    output.push_back(nums[index]);
    solve(index+1,output,res,nums);

    ouput.pop_back();
    solve(index+1,output,res,nums);

}

vector<vector<int>> subsetsWithDup(vector<int> nums){
    sort(nums.begin(),nums.end());
    vector<int> output;
    vector<vector<int>> res;
    int index=0;
    solve(index,output,res,nums);
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    return res;
}