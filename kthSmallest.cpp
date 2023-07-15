#include<bits/stdc++.h>
using namespace std;

int kthsmallest(vector<int> &A, int B) {
    priority_queue<int> q;  //max heap
    for(int i=0;i<A.size();i++){
        q.push(A[i]);
        if(q.size()>B){
            q.pop();
        }
    }
    return q.top();
}