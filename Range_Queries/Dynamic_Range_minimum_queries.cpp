#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void build(vector<ll>&arr, vector<ll>&v, ll s, ll e, ll index)
{
    if(s>e)
    return;
    
    if(s==e){
    arr[index]=v[s];
    return;
    }
    
    ll mid=(s+e)/2;
    build(arr,v,s,mid,2*index);
    build(arr,v,mid+1,e,2*index+1);
    arr[index]=min(arr[2*index],arr[2*index+1]);
}
void update(vector<ll>&arr,ll s, ll e,ll pos,ll val,ll index)
{
    if(pos<s||pos>e)
    return;
    if(s==e && s==pos){
    arr[index]=val;
    return;
    }
    
    ll mid=(s+e)/2;
    update(arr,s,mid,pos,val,2*index);
    update(arr,mid+1,e,pos,val,2*index+1);
    ll left=arr[2*index];
    ll right=arr[2*index+1];
    arr[index]=min(left,right);
}
int query(vector<ll>&arr, ll s, ll e,ll x, ll y, ll index)
{
    if(x>e||y<s)
    return INT_MAX;
    if(s>=x && e<=y)
    return arr[index];
    
    ll mid=(s+e)/2;
    ll left=query(arr,s,mid,x,y,2*index);
    ll right=query(arr,mid+1,e,x,y,2*index+1);
    return min(left,right);
}
int main()
{
    ll n,q;
    cin>>n>>q;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    cin>>v[i];
    vector<ll>arr(4*n+1);
    build(arr,v,0,n-1,1);
    // for(auto i:arr)
    // cout<<i<<" ";
    while(q--)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        if(x==1)
        {
            update(arr,0,n-1,y-1,z,1);
        }
        else if(x==2)
        {
            cout<<query(arr,0,n-1,y-1,z-1,1)<<endl;
        }
        
    }
    return 0;
}