/*square root of a number using binary search
we know root(37) lies between [0,1,2,....,35,36,37] the space where our ans lies is known as SEARCH SPACE*/
#include<bits/stdc++.h>
using namespace std;

long long int mysqt(long long int x){
    int s=0;
    int e=x;
    long long int mid=s+(e-s)/2;
    long long int ans;
    while(s<=e){
        long long int sq=mid*mid;
        if(sq > x){
            e=mid-1;
        }
        else if(sq < x){
            ans=mid;
            s=mid+1;
        }
        else if(sq == x){
            return mid;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

double sqtprecision(int x,int p,int int_sol){
    double ans=int_sol;
    double factor=1;
    for(int i=0;i<p;i++){
        factor/=10;
        for(double j=ans;j*j<x;j+=factor){
            ans=j;
        }
    }
    return ans;
}

int main(){
    long long int n;
    cin>>n;
    int temp=mysqt(n);
    cout<<sqtprecision(n,5,temp);
    return 0;
}


