#include<bits/stdc++.h>
using namespace std;

void bubble(int arr[],int n){
    if(n==0 || n==1){
        return ;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubble(arr,n-1);
}

void merge(int arr[],int s,int e){
    int mid=s+(e-s)/2;
    int l1=mid+1-s;
    int l2=e-mid;
    int a1[l1],a2[l2];
    int index=s;
    for(int i=0;i<l1;i++){
        a1[i]=arr[index++];
    }
    index=mid+1;
    for(int i=0;i<l2;i++){
        a2[i]=arr[index++];
    }
    int x=0,y=0;
    int z=s;
    while(x<l1 && y<l2){
        if(a1[x]<a2[y]){
            arr[z++]=a1[x++];
        }
        else{
            arr[z++]=a2[y++];
        }
    }
    while(x<l1){
        arr[z++]=a1[x++];
    }
    while(y<l2){
        arr[z++]=a2[y++];
    }
}

void mergesort(int arr[],int s,int e){
    if(s>=e){
        return ;
    }
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}

void quicksort(int arr[],int low,int high){
    if(low>=high){
        return ;
    }
    int l=low;
    int r=high;
    int mid=low+(high-low)/2;
    while(l<r){
        while(arr[l]<arr[mid]){
            l++;
        }
        while(arr[r]>arr[mid]){
            r--;
        }
        if(l>r){
            break;
        }
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
    quicksort(arr,low,r);
    quicksort(arr,l,high);
    
}

int main(){
    int arr[7]={2,7,9,4,12,1,5};
    //bubble(arr,6);
    //mergesort(arr,0,5);
    quicksort(arr,0,6);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
}