//prefix sum and hash map
//using the formula as: 
//if n is sum x is remainder and t is the no for dividing
// n=kt+x
// now we take some of bigger array then
// l =mt+x
//subarray divisible by t is
//l-n = (m-n)t;

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    ll sum=0;
    ll cnt=0;
    int rem=0;
    unordered_map<int,int>mp;
    mp[rem]=1;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        rem=sum%n;
        if(rem<0)
        rem+=n;
        if(mp.find(rem)!=mp.end())
        {
            cnt+=mp[rem];
            mp[rem]++;
        }
        else
        mp[rem]=1;
    }
    cout<<cnt<<endl;
    return 0;
}