//Solution 1- using ordered_set to take repeated element
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>


int main()
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    cin>>v[i];
    
   
    
   ordered_set s;
   for(ll i=0;i<n;i++)
   {
       s.insert({i,v[i]});
   }
   vector<ll>ans;
   for(ll i=0;i<n;i++)
   {
       ll x;
       cin>>x;
       auto val = *(s.find_by_order(x-1));
       cout<<val.second<<" ";
       s.erase(val);
   }
//   for(auto i:ans)
//   cout<<i<<" ";
   return 0;
    
}