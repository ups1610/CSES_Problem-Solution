//TLE need to be optimised
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll median(multiset<int>&s)
{
    vector<int>v;
    for(auto i:s)
    v.push_back(i);
    ll n=v.size();
    if(n%2!=0)
    return v[(n-1)/2];
    else
    return min(v[(n-1)]/2,v[((n-1)/2)+1]);
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int i=0,j=0;
    multiset<int>s;
    vector<int>ans;
    while(j<n)
    {
        s.insert(v[j]);
        if(j-i+1<k)
        j++;
        else if((j-i+1)==k)
        {
            ans.push_back(median(s));
            s.erase(v[i]);
            i++;
            j++;
        }
    }
    for(auto i:ans)
    cout<<i<<" ";
    return 0;
}