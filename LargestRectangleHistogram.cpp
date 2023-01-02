#include<bits/stdc++.h>
using namespace std;

vector<int> nextsmaller(vector<int> heights,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1;i>=0;i--){
        int curr=heights[i];
        while(s.top()!=-1 && heights[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);            
    }
    return ans;
}
vector<int> prevsmaller(vector<int> heights,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=0;i<n;i++){
        int curr=heights[i];
        while(s.top()!=-1 && heights[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);            
    }
    return ans;
}
int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    vector<int> next(n);
    next=nextsmaller(heights,n);
    vector<int> prev(n);
    prev=prevsmaller(heights,n);
    int area=INT_MIN;
    for(int i=0;i<n;i++){
        int len=heights[i];
        if(next[i]==-1){
            next[i]=n;
        }
        int bre=next[i]-prev[i]-1;
        int newarea=len*bre;
        area=max(area,newarea);
    }
    return area;
}