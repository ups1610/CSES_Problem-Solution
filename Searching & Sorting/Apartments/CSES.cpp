#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>vp(n),ap(m);
        for(int i=0;i<n;i++)
        {
            cin>>vp[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>ap[i];
        }
        
        sort(vp.begin(),vp.end());
        sort(ap.begin(),ap.end());
        int cnt=0,i=0,j=0;
        while(i<vp.size() && j<ap.size())
        {
             if(abs(ap[j]-vp[i])<=k){
             cnt++;
             i++;
             j++;
             }
             else if(ap[j]>vp[i])
             i++;
             else
             j++;
        }
        cout<<cnt<<endl;
    return 0;
}