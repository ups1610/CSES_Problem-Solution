//use of ordered set to improve time complexity nlogn make sure to use librray to use given in code
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
int main()
{
    int n,k;
    cin>>n>>k;
    ordered_set s;
    for(int i=1;i<=n;i++)
    s.insert(i);
    
    int val=k%n;
    for(int i=0;i<n;i++)
    {
        cout<<*(s.find_by_order(val))<<" ";
        s.erase(*(s.find_by_order(val)));
        if(!s.empty())
        val=(val+k)%s.size();
    }
    return 0;
}