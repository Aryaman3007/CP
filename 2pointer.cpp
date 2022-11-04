/*  21UEC005_Aryaman_Singh   */
#include <bits/stdc++.h>
#define loopf for(ll i=0;i<n;i++)
#define A ios_base::sync_with_stdio(false);
#define R cin.tie(NULL);
#define Y cout.tie(NULL);
#define ll long long int
#define tcs ll T;cin>>T;while(T--)
#define vecas for(ll i=0;i<n;i++) {ll x; cin>>x; v.push_back(x);}
using namespace std;

int main()
{
    A R Y
    tcs
    {
        ll n,k;
        cin >> n>>k;
        set<int>s;
        loopf{
            ll x;
            cin>>x;
            s.insert(x);
        }
        vector<int> v1;
        ll j=0;
        for(int i=1;i<=2*n;i++){
            if(i!=s[j]){
                v1.push_back(i);
            }
            else if(j>n){
                break;
            }
            else{
                j++;
            }
        }
        ll sum=0;
        ll maxi=INT_MIN;
        ll len=v1.size();
        while(k>0){
            s.insert(v1[len-1]);
            k--;
            sum=s[s.size()-1]-v1[len-1];
            len--;
            maxi=max(sum,maxi);
        }
        cout<<maxi<<endl;
    }
    
        // ll n;
        // cin>>n;
        // ll arr[n];
        // loopf{
        //     cin>>arr[i];
        // }
        // bool flag=false;
        // ll cnt=0,c=0,x=0;
        // ll m=n/2;
        // vector<int> v1;
        // vector<int> v2;
        // for(int i=n/2-1;i>=0;i--){
        //     v1.push_back(arr[i]);
        // }
        // if(n%2==0){
        //     for(int i=n/2;i<n;i++){
        //        v2.push_back(arr[i]);
        //     }
        // }
        // else{
        //     for(int i=n/2+1;i<n;i++){
        //        v2.push_back(arr[i]);
        //     }
        // }
        // vector<int> v3;
        // for(int i=0;i<v1.size();i++){
        //     v3.push_back(v2[i]-v1[i]);            
        // }
        // for(int i=1;i<v3.size();i++){
        //     if(v3[i]<v3[i-1]){
        //         flag=true;
        //     }           
        // }
        // for(int i=0;i<v3.size();i++){
        //     if(v3[i]<0){
        //         flag=true;
        //     }
        // }
        // if(flag){
        //     cout<<-1<<endl;
        // }
        // else{
        //     cout<<v3[v3.size()-1]<<endl;
        // }
    return 0;
}