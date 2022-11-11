#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    vector<int>pre;
    pre.push_back(0);
    int s=0;
    sort(v.begin(),v.end());
    long long ans=1;
    for(int i=0;i<n;i++)
    {
        if(ans<v[i])
        break;
        else
        {
            ans+=v[i];
        }
    }
    cout<<ans<<endl;
}