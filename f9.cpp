/*binary seatch is only valid for monotonic functions
elements should be in increasing or decreasing order*/

#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[],int size,int key){  //TC O(logN)
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2; //optimized way is mid=start + (end-start)/2 because this mid will not work for 2^31-1 int range
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }

        if(key>arr[mid]){
            start=mid+1;
        }

        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;

}
int main()
{
    int even[6]={2,4,6,8,10,12};
    int odd[6]={1,3,5,7,9,11};
    int index=binarysearch(even,6,10);
    int index1=binarysearch(odd,6,1);
    cout<<index<<endl<<index1;
    
} 


