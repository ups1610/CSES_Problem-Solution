//Variable size sliding window fail in negative number cases so use prefix sum along with map technique
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    cin>>v[i];
    unordered_map<ll,ll>mp;
    ll sum=0;
    ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum==x)
        cnt++;
        if(mp.find(sum-x)!=mp.end())
        cnt+=mp[sum-x];
        mp[sum]++;
    }
    cout<<cnt<<endl;
}

