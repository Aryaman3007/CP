#include<bits/stdc++.h>
using namespace std;

void  pattern1(int n){
    if(n==0){
        return ;
    }
    pattern1(n-1);
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

void pattern2(int n){
    if(n==1){
        cout<<1<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    pattern2(n-1);
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

int fib(int n){
    if(n==1 || n==2){
        return n-1;
    }
    return fib(n-1)+fib(n-2);
}

int main(){
    int x;
    cin>>x;
    //pattern1(x);
    //pattern2(x);
    cout<<fib(x);
}