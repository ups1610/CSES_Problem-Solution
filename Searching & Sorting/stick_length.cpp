//CSES PROBLEM
//Median approach
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    sort(v.begin(),v.end());
    int median=0;
    if(n%2)
      median=v[((n+1)/2)-1];
    else
      median=(v[n/2-1]+v[((n+1)/2)-1])/2;
    
    ll cost=0;
    for(int i=0;i<n;i++)
    {
        cost+=abs(median-v[i]);
    }
    cout<<cost<<endl;
    return 0;
}