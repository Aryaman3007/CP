#include<bits/stdc++.h>
using namespace std;

bool ispossible(int arr[],int a,int b,int mid){
    int cowcount=1;
    int x=arr[0];
    for(int i=1;i<a;i++){
        if((arr[i]-x)>=mid){
            cowcount++;
            if(cowcount==b){
                return true;
            }
            x=arr[i];            
        }        
    }
    return false;
}

int aggresivecow(int arr[],int a,int b){
    int s=0;
    int e=*max_element(arr,arr+a)-*min_element(arr,arr+a);
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(ispossible(arr,a,b,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        cout<<aggresivecow(arr,n,k)<<endl;
    }
}