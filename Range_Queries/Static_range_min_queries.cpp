//segment tree implementation and query selection function usage
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void build(vector<int>&arr,vector<int>&v,int index,int s,int e)
{
    if(s>e)
    return;
    if(s==e){
    arr[index]=v[s];
    return;
    }
    
    int mid=(s+e)/2;
    build(arr,v,2*index,s,mid);
    build(arr,v,2*index+1,mid+1,e);
    
    int left=arr[2*index];
    int right=arr[2*index+1];
    arr[index]=min(left,right);
}
int query(vector<int>&arr,int qs,int qe,int s,int e,int index)
{
    if(qs>e||qe<s)
    return INT_MAX;
    if(s>=qs && e<=qe)
    return arr[index];
    
    int mid=(s+e)/2;
    int left=query(arr,qs,qe,s,mid,2*index);
    int right=query(arr,qs,qe,mid+1,e,2*index+1);
    return min(left,right);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    vector<int>arr(4*n+1,0);
    build(arr,v,1,0,n-1);
    // for(auto i:arr)
    // cout<<i<<" ";
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        cout<<query(arr,x-1,y-1,0,n-1,1)<<endl;
    }
    return 0;
}