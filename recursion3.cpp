#include<bits/stdc++.h>
using namespace std;

int sum(int x){  //TC O(n)
    if(x==0){
        return 0;
    }
    return x+sum(x-1);
}

int sum_digit(int x){  //TC O(no. of digits)
    if(x==0){
        return 0;
    }
    return x%10+sum_digit(x/10);
}

int fact(int x){
    if(x==0){
        return 1;
    }
    return x*fact(x-1);
}

int main(){
    int n;
    cin>>n;
    //cout<<sum(n);
    //cout<<sum_digit(n);
    cout<<fact(n);
}