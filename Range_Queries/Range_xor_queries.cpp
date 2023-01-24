//simple segment tree implementation
//arr->[3,2,4,5,1,1,5,3] cses example
// tree implementation
//                   4
//                /     \
//               0        4
//             /   \    /   \
//            1    1   0     4
//           /\   /\  /\     /\
//          3  2 4 5 1  1   5  3 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

//Tree formation
void build(vector<ll>&arr,vector<ll>&v,ll s, ll e, ll index)
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
    ll left=arr[2*index];
    ll right=arr[2*index+1];
    arr[index]=(left^right);
}

// Range xor sum function
ll query(vector<ll>&arr,ll s,ll e, ll x, ll y,ll index)
{
    if(x>e||y<s)
    return 0;
    if(s>=x && e<=y)
    return arr[index];
    
    ll mid=(s+e)/2;
    ll left=query(arr,s,mid,x,y,2*index);
    ll right=query(arr,mid+1,e,x,y,2*index+1);
    return (left^right);
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
    build(arr,v,0,n-1,1);
    // for(auto i:arr)
    // cout<<i<<" ";
    // cout<<endl;
    while(m--)
    {
        ll x,y;
        cin>>x>>y;
        cout<<query(arr,0,n-1,x-1,y-1,1)<<endl;
    }
    return 0;
}