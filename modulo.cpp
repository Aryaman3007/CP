/*given a number N.print its factorial constraints
1<=N<=100 
print answer module M where 
M=10 ^9 +7 - very close to integer maximum 
MM -> Multiplicative inverse (M is a prim no.)
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n;
    cin>>n;
    int M=47;
    ll fact=1;
    for(int i=2;i<=n;i++){
        fact=(fact*i) %M;
    }
    cout<<fact;   
    
    return 0;
}
