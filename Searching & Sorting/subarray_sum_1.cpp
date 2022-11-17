//variable size sliding window O(N)
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int i=0,j=0;
    ll sum=0,cnt=0;
    while(j<v.size())
    {
        sum+=v[j];
        if(sum<x)
        j++;
        else if(sum==x)
        {
            cnt++;
            j++;
        }
        else if(sum>x)
        {
            while(sum>x)
            {
                sum-=v[i];
                i++;
                if(sum==x)
                cnt++;
            }
            j++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}