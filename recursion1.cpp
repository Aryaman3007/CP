/*  21UEC005_Aryaman_Singh   */
#include <bits/stdc++.h>
#define loopf for(ll i=0;i<n;i++)
#define A ios_base::sync_with_stdio(false);
#define R cin.tie(NULL);
#define Y cout.tie(NULL);
#define tcs ll T;cin>>T;while(T--)
#define ll long long int
#define vecas vector<ll> v; for(ll i=0;i<n;i++) {ll x; cin>>x; v.push_back(x);}
using namespace std;

int sum(int n){
    if(n==0){
        return 0;
    }
    else{
        return n+sum(n-1);
    }
}
int power(int n,int p){
    if(p==0){  //base condition
        return 1;
    }
    else{
        return n*power(n,p-1);
    }
}

int fact(int n){
    if(n==0){ //base condition
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}

int fib(int n){
    if(n==0 || n==1){ //base case
        return n;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}

int main()
{
    A R Y
    // int x,p;
    // cin>>x>>p;
    //cout<<sum(x);  
    //cout<<power(x,p); 
    int m;
    cin>>m;
    //cout<<fact(m);
    cout<<fib(m);
    return 0;
}
