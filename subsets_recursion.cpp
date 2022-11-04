#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> v,vector<int> output,int index,vector<vector<int>> &ans){
    //{1,2,3} {}
    if(index>=v.size()){
        ans.push_back(output);
        return ;
    }

    //exclude element    
    solve(v,output,index+1,ans);

    //include element
    int element=v[index];
    output.push_back(element);
    solve(v,output,index+1,ans);

}

vector<vector<int>> subsets(vector<int>v){
    int n=v.size();
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(v,output,index,ans);
    return ans;    
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    subsets(v);
}