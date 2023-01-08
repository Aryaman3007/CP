#include<bits/stdc++.h>
using namespace std;

//Approach 1 using stack

queue<int> rev(queue<int> q){
    stack<int> temp;
    while(!q.empty()){
        int x=q.front();
        temp.push(x);
        q.pop();
    }
    while(!temp.empty()){
        int y=temp.top();
        ans.push(y);
        temp.pop();
    }

    return ans;
}

//Approach 2 using recursion

void solve(queue<int> &q,queue<int> &ans){
    if(q.empty()){
        return ;
    }
    int x=q.front();
    q.pop();
    solve(q,ans);
    ans.push(x);
}

queue<int> rev(queue<int> q){
    queue<int> ans;
    solve(q,ans);
    return ans;
}