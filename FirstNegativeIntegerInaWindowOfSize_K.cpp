#include<bits/stdc++.h>
using namespace std;

//Using doubly ended queue(deque)

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    vector<long long> ans;
    deque<long long> dq;

    for(int i=0;i<K;i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }
    
    if(dq.size>0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    for(int i=K;i<N;i++){
        if((i-dq.front())>=K && !dq.empty()){
            dq.pop_front();
        }

        if(A[i]<0){
            dq.push_back(i);
        }

        if(dq.size>0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }

    return ans;
}