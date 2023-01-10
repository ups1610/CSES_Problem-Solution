// simple prefix sum implementation and indexing
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>v(n);
    ll sum=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        sum+=x;
        v[i]=sum;
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<v[b]-v[a-1]<<endl;
    }
    return 0;
}