//Peak index in a mountain array
//pivot element in a rotated sorted array
//search an element in a rotated sorted array
#include<bits/stdc++.h>
using namespace std;

int peak(int arr[],int x){  //O(logN)
    int s=0;
    int e=x-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int pivot(int arr[],int x){
    int s=0;
    int e=x-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int binary_search(int arr[],int s,int e,int key){
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int search_rotated(int arr[],int x,int key){
    int a=pivot(arr,x);
    if(key>arr[0]){
        return binary_search(arr,0,a-1,key);          
    }
    else if(key<arr[0]){    
        return binary_search(arr,a,x-1,key); 
    }
    else{
        return 0;
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    //cout<<peak(ar,n);
    cout<<search_rotated(ar,n,k);
    return 0;    
}