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

bool sorted(int arr[],int x){ //for increasing order 
    if(x==1){  //base condition when only the last element is left
        return true;
    }
    else{
        return (arr[0]<arr[1] && sorted(arr+1,x-1)); //arr+1 is tothe pointer of the new array with length n-1
    }
}

void dec(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    dec(n-1);
}

void inc(int n){
    if(n==0){
        return;
    }
    inc(n-1);
    cout<<n<<" ";
}


int main()
{   
    A R Y
    // int n;
    // cin>>n;
    // int ar[n];
    // loopf{
    //     cin>>ar[i];
    // }  
    // cout<<sorted(ar,n);
    int x;
    cin>>x;
    dec(x);  
    cout<<endl;
    inc(x);
    return 0;
}