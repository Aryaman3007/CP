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

int firstocc(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstocc(arr,n,i+1,key);
}
int lastocc(int arr[],int n,int i,int key){
    
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return lastocc(arr,n,i-1,key);
}

int main()
{
    A R Y
    int x;
    cin>>x;
    int a[x];
    for(int i=0;i<x;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    cout<<firstocc(a,x,0,k)<<endl;  
    cout<<lastocc(a,x,x-1,k);
    return 0;
}