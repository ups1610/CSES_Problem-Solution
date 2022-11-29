#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
     cin>>v[i];
    
    ordered_set s;
    for(int i=0;i<k;i++)
    s.insert({v[i],i});
    ll mid=0;
    vector<int>ans;
    mid=s.find_by_order((k+1)/2-1)->first;
    ll cost=0;
    for(int i=0;i<k;i++){
    cost+=abs(v[i]-mid);
    }
    cout<<cost<<" ";
    ll j=0;
    ll n_mid=0;
    // cout<<cost<<" ";
    for(int i=0;i<n-k;i++)
    {
        s.erase({v[i],i});
        s.insert({v[i+k],i+k});
        n_mid=s.find_by_order((k+1)/2-1)->first;
        cost=cost-abs(mid-v[i])+abs(v[i+k]-n_mid);
        if(k%2==0)
        cost-=(n_mid-mid);
        cout<<cost<<" ";
        mid=n_mid;
        j++;
    }
    
    // for(auto i:ans)
    // cout<<i<<" ";
    // cout<<"\n";
    return 0;
}