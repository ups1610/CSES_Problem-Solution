//Variable size sliding window approach
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
        unordered_map<int,int>mp;
        int i=0,j=0;
        int ans=0,len=0;
    while(j<n)
    {
        if(mp.find(v[j])==mp.end()||mp[v[j]]==0)
        {
            mp[v[j]]++;
            len++;
            ans=max(ans,len);
            j++;
        }
        else
        {
            len--;
            mp[v[i]]--;
            i++;
        }
        
    }
    cout<<ans<<endl;
}