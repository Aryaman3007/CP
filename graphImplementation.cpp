#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;  //O(2E) space with E edges n->nodes m->edges
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(auto it:adj){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}