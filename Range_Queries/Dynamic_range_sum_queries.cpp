//implementation of segment tree with sum values and update function based on sum  
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void update(vector<ll>&arr,ll s,ll e,ll index,ll pos,ll val)
{
    if(pos>e || pos<s)
    return;
    
    if(s==e && s==pos){
    arr[index]+=val;
    return;
    }
    
    ll mid=(s+e)/2;
    update(arr,s,mid,2*index,pos,val);
    update(arr,mid+1,e,2*index+1,pos,val);
    arr[index]=(arr[2*index]+arr[2*index+1]);
}
void sum(vector<ll>&arr,vector<ll>&v,ll s, ll e,ll index)
{
    if(s>e)
    return;
    if(s==e)
    {
        arr[index]=v[s];
        return;
    }
    
    ll mid=(s+e)/2;
    sum(arr,v,s,mid,2*index);
    sum(arr,v,mid+1,e,2*index+1);
    ll left=arr[2*index];
    ll right=arr[2*index+1];
    arr[index]=left+right;
}
ll query(vector<ll>&arr,ll s,ll e,ll x, ll y,ll index)
{
    if(x>e || y<s)
    return 0;
    if(s>=x && e<=y)
    return arr[index];
    
    ll mid=(s+e)/2;
    ll left=query(arr,s,mid,x,y,2*index);
    ll right=query(arr,mid+1,e,x,y,2*index+1);
    return (left+right);
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<ll>arr(4*n+1);
    sum(arr,v,0,n-1,1);
    // for(auto i:arr)
    // cout<<i<<" ";
    while(m--)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        if(x==1)
        {
          update(arr,0,n-1,1,y-1,z-v[y-1]); 
          v[y-1]=z;
        }
        else if(x==2)
        {
        cout<<query(arr,0,n-1,y-1,z-1,1)<<endl;
        }
    }
    return 0;
}