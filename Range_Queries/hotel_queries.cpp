//segment tree build max and update query by observation
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void build(vector<ll>&arr,vector<ll>&v,ll s, ll e, ll index)
{
    if(s>e)
    return;
    if(s==e){
    arr[index]=v[s];
    return;
    }
    
    ll mid = (s+e)/2;
    build(arr,v,s,mid,2*index);
    build(arr,v,mid+1,e,2*index+1);
    arr[index]=max(arr[2*index],arr[2*index+1]);
    
}

void query(vector<ll>&arr,ll s,ll e, ll index, ll val)
{
    if(s==e)
    {
        arr[index]-=val;
        cout<<s+1<<" ";
        return;
    }
    ll mid = (s+e)/2;
    if(arr[2*index]>=val)
        query(arr,s,mid,2*index,val);
    else
        query(arr,mid+1,e,2*index+1,val);
        
    arr[index]=max(arr[2*index],arr[2*index+1]);    
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>v(n) ;
    for(ll i=0;i<n;i++)
    cin>>v[i];
    
    vector<ll>arr(4*n+1);
    build(arr,v,0,n-1,1);
    while(m--)
    {
        ll x;
        cin>>x;
        if(arr[1]<x)
          cout<<0<<" ";
        else
        query(arr,0,n-1,1,x);
    }
    return 0;
}