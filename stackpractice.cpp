#include<bits/stdc++.h>
using namespace std;

void deletemiddleelement(stack<int> &s,int n,int count){
    if(count==n/2){
        s.pop();
        return;
    }

    int num=s.top();
    s.pop();
    deletemiddleelement(s,n,count+1);
    s.push(num);    
}

void insertatbottom(stack<int> &s, int ch){
    if(s.empty()){
        s.push(ch);
        return;
    }

    int num=s.top();
    s.pop();
    insertatbottom(s,ch);
    s.push(num);
}

void reversestack(stack<int> &st){

    if(st.empty()){
        return;
    }

    int ch=st.top();
    ch.pop();
    reversestack(st);
    insertatbottom(st,ch);
}

