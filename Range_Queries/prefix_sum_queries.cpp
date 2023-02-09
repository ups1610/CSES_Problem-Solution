#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void build(vector<int>&arr,vector<int>&v,int s,int e, int index)
{
    if(s>e)
    return;
    if(s==e)
    {
        arr[index]=v[s];
        return;
    }
    int mid=(s+e)/2;
    build(arr,v,s,mid,2*index);
    build(arr,v,mid+1,e,2*index+1);
    arr[index]=arr[2*index]+arr[2*index+1];
}
void update(vector<int>&arr, int s, int e, int index, int pos, int val)
{
    if(s==e)
    {
        arr[index]=val;
        return;
    }
    int mid=(s+e)/2;
    if(pos<=mid)
    update(arr,s,mid,2*index,pos,val);
    else
    update(arr,mid+1,e,2*index+1,pos,val);
    
    arr[index]=arr[2*index]+arr[2*index+1];
}

int query(vector<int>&arr, int s, int e, int x, int y,int index)
{
    if(x>e||y<s)
    return 0;
    if(s>=x && e<=y)
    return arr[index];
    
    int mid=(s+e)/2;
    int left=query(arr,s,mid,x,y,2*index);
    int right=query(arr,mid+1,e,x,y,2*index+1);
    return left+right;
}
int main()
{
   int n,m;
   cin>>n>>m;
   vector<int>v(n+1);
   for(int i=1;i<=n;i++)
   cin>>v[i];
   
   vector<int>arr(4*n+1);
   build(arr,v,1,n,1);
   while(m--)
   {
       int a;
       cin>>a;
       if(a==2)
       {
           int x,y;
           cin>>x>>y;
           cout<<query(arr,1,n,x,y,1)<<endl;
       }
       else
       {
           int p,val;
           cin>>p>>val;
           update(arr,1,n,1,p,v[p]=val);
       }
   }
   return 0;
}