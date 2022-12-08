//connected components with dfs implementation
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>grp[],int node,vector<int>&vis)
{
    vis[node]=1;
    for(auto it:grp[node])
    {
        if(!vis[it])
        dfs(grp,it,vis);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>grp[n+1];
    vector<int>vis(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        grp[x].push_back(y);
        grp[y].push_back(x);
    }
    int cnt=0;
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cnt++;
            ans.push_back(i);
            dfs(grp,i,vis);
        }
    }
    
    cout<<cnt-1<<endl;
    if(cnt>1)
    {
        for(int i=0;i<ans.size()-1;i++)
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    return 0;
}