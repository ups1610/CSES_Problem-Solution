#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,n;
    cin>>x>>n;
    set<int>s;
    multiset<int>ms;
    s.insert(0);
    s.insert(x);
    ms.insert(x-0);
    for(int i=0;i<n;i++)
    {
        int pos;
        cin>>pos;
        s.insert(pos);
        auto it=s.find(pos);
        int nxt=*next(it);
        int prv=*prev(it);
        ms.erase(ms.find(nxt-prv));
        ms.insert(nxt-pos);
        ms.insert(pos-prv);
        cout<<*ms.rbegin()<<" ";
    }
    cout<<endl;
    return 0;
}