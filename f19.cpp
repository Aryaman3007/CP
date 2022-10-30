#include<bits/stdc++.h>
using namespace std;

void movezero(int arr[],int x){
    int i=0;
    for(int j=0;j<x;j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    movezero(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
