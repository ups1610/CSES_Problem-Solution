//Aproach 1 (using set)
#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    vector<ll>nums(n);
    
    vector<ll>prefix(n+1);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        prefix[i]=a+prefix[i-1];
    }
    
    set<pair<ll,int>>s;
    ll ans=-inf;
    int j=0;
   for(int i=a;i<=b;i++)
   {
       s.insert({prefix[i],i});
   }
   for(int i=1;i<=n-a+1;i++)
   {
       ans=max(ans,s.rbegin()->first-prefix[i-1]);
       s.erase({prefix[i+a-1],i+a-1});
       if(i+b<=n)
       s.insert({prefix[i+b],i+b});
   }
   cout<<ans<<endl;
   return 0;
}