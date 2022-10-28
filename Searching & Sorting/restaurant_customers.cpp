// For interval questions approach will be assign +1 to start time and -1 to end time then apply algorithm
//CSES -> https://cses.fi/problemset/result/4885650/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,1});
        v.push_back({y,-1});
    }
    sort(v.begin(),v.end());
    int mx=0;
    int sum=0;
    for(auto i:v)
    {
       sum+=i.second;
       mx=max(mx,sum);
    }
    cout<<mx<<endl;
    return 0;
}