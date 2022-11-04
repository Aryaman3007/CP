#include<bits/stdc++.h>
using namespace std;

void mergesorted(int arr1[],int n,int arr2[],int m,int arr3[]){
    int i=0;
    int j=0;
    int x=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            arr3[x++]=arr1[i++];
        }
        else{
            arr3[x++]=arr2[j++];
        }
    }
    while(i<n){
        arr3[x++]=arr1[i++];
    }
    while(j<m){
        arr3[x++]=arr2[j++];
    }
}

int main(){
    int n,m;
    cin>>n>>n;
    int arr1[n];
    int arr2[m];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    int arr3[n+m];
    mergesorted(arr1,n,arr2,m,arr3);
    for(int i=0;i<n+m;i++){
        cout<<arr3[i]<<" ";
    }

    return 0;
}