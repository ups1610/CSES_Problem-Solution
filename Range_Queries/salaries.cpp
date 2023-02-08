//ordered_set with pair and to handle long case by counting the the range
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
    ordered_set s;
    ll n,q;
    cin>>n>>q;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    cin>>v[i];
    for(ll i=0;i<n;i++){
       s.insert({v[i],i});
    }
    while(q--)
    {
        char ch;
        cin>>ch;
        if(ch=='!')
        {
            int l,val;
            cin>>l>>val;
            s.erase({v[l-1],l-1});
            v[l-1]=val;
            s.insert({v[l-1],l-1});
        }
        else
        {
            ll x,y;
            cin>>x>>y;
            ll a=s.order_of_key({x-1,1e9});
            ll b=s.order_of_key({y,1e9});
            cout<<b-a<<endl;
        }
    }
    return 0;
}