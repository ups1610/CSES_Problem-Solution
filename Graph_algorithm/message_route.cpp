// simple bfs from source to destination with shortest path problem refer geeks for geeks for understanding..
#include<bits/stdc++.h>
using namespace std;
int bfs(vector<int>adj[],vector<int>&path,vector<int>&dis,vector<int>&vis,int src,int n)
{
    queue<int>q;
    q.push(src);
    vis[src]=1;
    dis[src]=0;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(auto it:adj[p])
        {
            if(!vis[it])
            {
                dis[it]=dis[p]+1;
                vis[it]=1;
                path[it]=p;
                q.push(it);
                if(it==n)
                  return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>dis(n+1,INT_MAX);
    vector<int>vis(n+1,0);
    vector<int>path(n+1,-1);
    int val=bfs(adj,path,dis,vis,1,n);
    if(!val){
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
    }
    vector<int>ans;
    int c=n;
    ans.push_back(c);
    while(path[c]!=-1)
    {
        ans.push_back(path[c]);
        c=path[c];
    }
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1;i>=0;i--)
    cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}