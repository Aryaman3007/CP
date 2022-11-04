#include<bits/stdc++.h>
using namespace std;

bool reverse(string &s,int i,int j){
    if(i>j){
        return true;
    }
    if(s[i]!=s[j]){
        return false;
    }
    else{
        reverse(s,i+1,j-1);
    }
    return true;
}

int power(int n,int m){
    if(m==0){
        return 1;
    }
    else if(m==1){
        return n;
    }
    int ans=power(n,m/2);
    if(m%2==0){
        return ans*ans;
    }
    else{
        return n*ans*ans;
    }
}

int main(){
    // string s="madam";
    // int l=s.size();
    // cout<<reverse(s,0,l-1);
    int a,b;
    cin>>a>>b;
    cout<<power(a,b);
}