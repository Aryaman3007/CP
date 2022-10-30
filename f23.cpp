#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    // for(int i=0;i<m;i++){
    //     if(i%2==0){
    //         for(int j=0;j<n;j++){
    //             cout<<arr[j][i]<<" ";
    //         }
    //     }
    //     else{
    //         for(int j=n-1;j>=0;j--){
    //             cout<<arr[j][i]<<" ";
    //         }
    //     }        
    // }
    int firstrow=0;
    int lastrow=n-1;
    int lastcol=m-1;
    int firstcol=0;
    int count=0;
    while(count<n*m){
        for(int i=firstcol;count<n*m && i<=lastcol;i++){
            cout<<arr[firstrow][i]<<" ";
            count++;
        }
        firstrow++;
        for(int j=firstrow;count<n*m && j<=lastrow;j++){
            cout<<arr[j][lastcol]<<" ";
            count++;
        }
        lastcol--;
        for(int j=lastcol;count<n*m && j>=firstcol;j--){
            cout<<arr[lastrow][j]<<" ";
            count++;
        }
        lastrow--;
        for(int i=lastrow;count<n*m && i>=firstrow;i--){
            cout<<arr[i][firstcol]<<" ";
            count++;
        }
        firstcol++;
    }

}