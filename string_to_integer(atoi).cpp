#include<bits/stdc++.h>
using namespaces std;

int myAtoi(string s) {
    stringstream ss(s);
    int i=0;
    for(int j=0;j<s.size();j++){
        if(s[j]==' '){
            i++;
        }
    }
    if(i==s.size()){
        return 0;
    }
    int x;
    ss>>x;
    if(x<pow(-2,31)){
        return pow(-2,31);
    }
    else if(x>pow(2,31) -1 ){
        return pow(2,31)-1;
    }
    return x;
    
}