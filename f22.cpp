#include<bits/stdc++.h>
using namespace std;

bool rotsorted(int arr[],int n){
    int cnt=0;
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            cnt++;
        }
    }
    if(arr[n-1]>arr[0]){
        cnt++;
    }
    return cnt<=1;
}
int main(){
    int n;
    cin>> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(rotsorted(arr,n)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}