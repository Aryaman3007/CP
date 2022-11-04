#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[],int n,int k){
    int arr1[n];
    for(int i=0;i<n;i++){
        arr1[(i+k)%n]=arr[i];        
    }
    for(int i=0;i<n;i++){
        arr[i]=arr1[i];
    }
}

bool reversearray(string s,int n){
    string s1=s;
    int sk=0;
    int e=n-1;
    while(sk<=e){
        swap(s[sk],s[e]);
        sk++;
        e--;
    }
    if(s==s1){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // //rotate(arr,n,k);
    // reversearray(arr,n,k);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // 
    string s;
    cin>>s;
    int n=s.size();
    cout<<reversearray(s,n);
}