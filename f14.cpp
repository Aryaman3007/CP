/*  21UEC005_Aryaman_Singh   */
#include <bits/stdc++.h>
#define ll long long int
#define loopf for(ll i=0;i<n;i++)
#define A ios_base::sync_with_stdio(false);
#define R cin.tie(NULL);
#define Y cout.tie(NULL);
#define tcs ll T;cin>>T;while(T--)
#define ll long long int
using namespace std;

void wave(int arr[],int a,int x){
    int s=0;
    int e=a-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]>x){
            e=mid-1;
        }
        else if(arr[mid]==x){
            ans=0;
            break;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    int l=a-e+1;
    if(ans==0){
        cout<<0<<endl;
    }
    else if(l%2==0){
        cout<<"POSITIVE\n";
    }
    else if(l%2!=0){
        cout<<"NEGATIVE\n";
    }
}

int main()
{
    A R Y
    int n,m;
    cin>>n>>m;
    int arr[n];
    loopf{
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<m;i++){
        int z;
        cin>>z;
        wave(arr,n,z);
    }
    return 0;
}