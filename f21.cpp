/*  21UEC005_Aryaman_Singh   */
#include <bits/stdc++.h>
#define loopf for(ll i=0;i<n;i++)
#define A ios_base::sync_with_stdio(false);
#define R cin.tie(NULL);
#define Y cout.tie(NULL);
#define ll long long int
#define tcs ll T;cin>>T;while(T--)
#define vecas vector<ll> v; for(ll i=0;i<n;i++) {ll x; cin>>x; v.push_back(x);}
using namespace std;
int count(string s, char c)
{
    // Count variable
    int res = 0;
 
    for (int i=0;i<s.length();i++)
 
        // checking character in string
        if (s[i] == c)
            res++;
 
    return res;
}

int main()
{
    
    A R Y
    tcs{
        ll n,k;
        cin >> n >> k;
        int arr[(2*n)+1]={0};
        loopf
        {
            cin>>arr[i];
        }
        int sum = 0;
        for(ll i=0;i<k;i++)
        {
            int mini,maxi;
            for (int i = 1; i <= 2*n; i++)
            {
                if (arr[i]==0)
                {
                   mini = i;
                   arr[i]++;
                   break;
                }
            }
            for (int i = 2*n; i >= 0; i--)
            {
                if(arr[i]==1){
                    maxi = i;
                    break;
                }
            }
            sum += maxi-mini;
         
        }        
        cout<<sum<<endl;
    }
    return 0;
}