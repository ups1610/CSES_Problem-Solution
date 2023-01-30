// Prefix sum in 2D array/matrix
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(1001,vector<int>(1001,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char x;
            cin>>x;
            if(x=='.')
            v[i][j]=0;
            else
            v[i][j]=1;
        }
    }
    vector<vector<int>>prefix(1001,vector<int>(1001,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            prefix[i][j]=v[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    // for(auto i:prefix)
    // {
    //     for(auto j:i)
    //     cout<<j<<" ";
    //     cout<<endl;
    // }
    while(m--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<(prefix[c][d]-prefix[c][b-1]-prefix[a-1][d]+prefix[a-1][b-1])<<endl;
        
    }
    return 0;
}