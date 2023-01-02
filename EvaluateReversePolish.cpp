#include<bits/stdc++.h>
using namespace std;

bool solve(string &s){
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            return true;
        }
    }
    return false;
}
int evalRPN(vector<string>& tokens) {
    int ans=0;
    stack<int> s;
    for(int i=0;i<tokens.size();i++){
        if(solve(tokens[i])){
            int x= stoi(tokens[i]);
            s.push(x);
        }
        else{
            int y=s.top();
            s.pop();
            int z=s.top();
            s.pop();
            if(tokens[i]=="+"){
                ans=z+y;                    
            }
            else if(tokens[i]=="-"){
                ans=z-y;                    
            }
            else if(tokens[i]=="*"){
                ans=z*y;                    
            }
            else if(tokens[i]=="/"){
                ans=z/y;                    
            }
            s.push(ans);
        }
    }
    return s.top();
}