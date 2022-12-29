#include<bits/stdc++.h>
using namespace std;

void insertsorted(stack<int> &st,int num){
    if(st.empty() || st.top()<num){
        st.push(num);
        return;
    }

    int temp=st.top();
    st.pop();
    insertsorted(st,num);
    st.push(temp);
}

void sortstack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int num=st.top();
    st.pop();
    sortstack(st);
    insertsorted(st,num);
}

/*int main(){
    stack<int> s;
    s.push(2);
    s.push(-2);
    s.push(4);
    s.push(3);
    s.push(1);
    sortstack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}*/