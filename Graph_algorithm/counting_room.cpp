//simple dfs implementation in grid
#include<bits/stdc++.h>
using namespace std;
#define ll long long int;
#define inf 1e18
vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
void dfs(vector<vector<int>>&vis, int i, int j,int n,int m)
{
    vis[i][j]=1;
    for(auto it:dir)
    {
        int x=i+it[0];
        int y=j+it[1];
        if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]){
        dfs(vis,x,y,n,m);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m,'#'));
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            v[i][j]=c;
            if(c=='#')
            vis[i][j]=1;
        }
    }
    // for(auto i:vis)
    // {
    //     for(auto j:i)
    //     cout<<j<<" ";
    //     cout<<endl;
    // }
    
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j]){
            dfs(vis,i,j,n,m);
            cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}