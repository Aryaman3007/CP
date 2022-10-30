/*Same question can be done for vector by changing the parameter of the function to vector<int> &arr*/
#include<bits/stdc++.h>
using namespace std;

int firstocc(int arr[],int x,int k){
    int s=0;
    int e=x-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==k){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>k){
            s=mid+1;
        }
        else if(arr[mid]<k){
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int lastocc(int arr[],int x,int k){
    int s=0;
    int e=x-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==k){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>k){
            s=mid+1;
        }
        else if(arr[mid]<k){
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    int ar[7]={2,1,7,4,9,9,4};
    cout<<firstocc(ar,7,4)<<" "<<lastocc(ar,7,4);
    //For total no. of occurences in an array we can use (lastindex-firstindex+1)
    return 0;
}