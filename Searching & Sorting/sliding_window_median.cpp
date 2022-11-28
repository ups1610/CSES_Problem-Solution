//simple use of ordered set
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    
    ordered_set s;
    vector<int>ans;
    for(int i=0;i<k;i++)
    {
        s.insert({v[i],i});
    }
    int j=0;
    cout<<s.find_by_order((k-1)/2)->first<<" ";
    for(int i=k;i<n;i++)
    {
        s.erase({v[j],j});
        s.insert({v[i],i});
        cout<<s.find_by_order((k-1)/2)->first<<" ";
        j++;
    }
    return 0;
    
}