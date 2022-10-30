#include<bits/stdc++.h>
using namespace std;

bool ispossible(int arr[],int n,int m,int x){
    int studentcount=1;
    int pagesum=0;
    for(int i=0;i<n;i++){
        if(arr[i]+pagesum<=x){
            pagesum+=arr[i];
        }
        else{
            studentcount++;
            if(arr[i]>x || studentcount>m){
                return false;
            }
            pagesum=arr[i];
        }
    }
    return true;
}

int bookallocate(int arr[],int n,int m){
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int ans=-1;
    int e=sum;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(ispossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int arr[a];
        for(int i=0;i<a;i++){
            cin>>arr[i];
        }
        cout<<bookallocate(arr,a,b)<<endl;

    }
}