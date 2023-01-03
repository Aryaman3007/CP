#include<bits/stdc++.h>
using namespace std;

bool knows(int a,int b,vector<vector<int> >& M, int n){
    if(M[a][b]==1){
        return true;
    }
    return false;
}

int celebrity(vector<vector<int> >& M, int n) 
{
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    
    while(s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        
        if(knows(a,b,M,n)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    
    int ans=s.top();
    
    for(int i=0;i<n;i++){
        if(M[i][ans]!=1 && i!=ans){
            return -1;
        }
    }
    
    for(int i=0;i<n;i++){
        if(M[ans][i]!=0 && i!=ans){
            return -1;
        }
    }
    return ans;
}