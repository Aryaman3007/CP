#include<bits/stdc++.h>
using namespace std;

bool issorted(int arr[],int n){
    if(n<=1){
        return true;
    }
    else if(arr[0]>arr[1]){
        return false;
    }
    else{
        return issorted(arr+1,n-1);
    }
}

int getsum(int *arr,int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return arr[0];
    }
    int remaining=getsum(arr+1,n-1);
    int sum=arr[0]+remaining;
    return sum;
}  

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //cout<<issorted(arr,n);
    cout<<getsum(arr,n);
}