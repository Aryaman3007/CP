#include<bits/stdc++.h>
using namespace std;

void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        swap(arr[i],arr[mini]);
    }
}

void bubblesort(int arr[],int n){
    for(int i=1;i<n;i++){ // no. of rounds
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int x=arr[i];
        int j=i-1;
        while(j>=0){
            if(x<arr[j]){
                arr[j+1]=arr[j] ;               
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1]=x;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}