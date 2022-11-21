// if we have at most 3 distinct integers then count will be considered as:
// given array 1 2 3 1 1
// 1 2 3 -> 3 subarray such as [1],[1,2],[1,2,3](hint)
//sliding window varaible size-> approach

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
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
    unordered_map<int,int>mp;
    ll cnt=0;
    i=0,j=0;
    while(j<n)
    {
        mp[v[j]]++;
        while(mp.size()>k)
        {
            mp[v[i]]--;
            if(mp[v[i]]==0)
            mp.erase(v[i]);
            i++;
        }
        cnt+=j-i+1;
        j++;
    }
 
    cout<<cnt<<endl;
    return 0;
}