#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> m;
void solve(vector<int>& v){
    stack<int>s;
    for(int i=v.size()-1;i>=0;--i){
        while(!s.empty() and s.top()<= v[i]){
            s.pop();
        }
        if(s.empty()){
            m[v[i]]=-1;
        }
        else{
            m[v[i]]=s.top();
        }
        s.push(v[i]);
    }
}
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int>ans;
    solve(nums2);
    for(auto x: nums1){
        ans.push_back(m[x]);
    }
    return ans;
}