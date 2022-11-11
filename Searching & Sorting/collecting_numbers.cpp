
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp.insert({v[i],i});
    }
    vector<int>ans;
    for(auto i:mp)
    ans.push_back(i.second);
    int cnt=1;
    for(int i=0;i<n-1;i++)
    {
        if(ans[i]>ans[i+1])
        cnt++;
    }
    cout<<cnt;
    return 0;
    
}