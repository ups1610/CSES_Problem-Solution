#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v(n),ar(m);
    multiset<int>s;
    for(int i=0;i<n;i++){
    int x;
    cin>>x;
    s.insert(x);
    }
    for(int i=0;i<m;i++)
    cin>>ar[i];
    
    for(int i=0;i<m;i++)
    {
        auto it=s.upper_bound(ar[i]);
        if(s.begin()==it)
        {
            cout<<-1<<endl;
           
        }
        else {
         it--;
            cout<<*it<<endl;
            s.erase(it);
        }
        
    }
   return 0;
}