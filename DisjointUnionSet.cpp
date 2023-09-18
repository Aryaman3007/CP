/*  21UEC005_Aryaman_Singh   */
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulti_u=findPar(u);
        int ulti_v=findPar(v);
        if(ulti_u==ulti_v) return;
        if(rank[ulti_u]>rank[ulti_v]){
            parent[ulti_v]=ulti_u;
        }
        else if(rank[ulti_u]<rank[ulti_v]){
            parent[ulti_u]=ulti_v;
        }
        else{
            parent[ulti_v]=ulti_u;
            rank[ulti_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulti_u=findPar(u);
        int ulti_v=findPar(v);
        if(ulti_u==ulti_v) return;
        if(size[ulti_u]<size[ulti_v]){
            size[ulti_u]=ulti_v;
            size[ulti_v]+=size[ulti_u];
        }
        else{
            size[ulti_v]=ulti_u;
            size[ulti_u]+=size[ulti_v];
        }
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif

    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    
    if(ds.findPar(3)==ds.findPar(7)){
        cout<<"Same\n";
    }
    else{
        cout<<"Not same\n";
    }

    ds.unionBySize(3,7);

    if(ds.findPar(3)==ds.findPar(7)){
        cout<<"Same\n";
    }
    else{
        cout<<"Not same\n";
    }
    
    return 0;
}