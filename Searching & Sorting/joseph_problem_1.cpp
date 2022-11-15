//Implement just a simple queue
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    queue<int>q;
    for(int i=1;i<=n;i++)
    q.push(i);
    int cnt=1;
    while(!q.empty())
    {
        if(cnt%2==0)
        {
            cout<<q.front()<<" ";
            q.pop();
        }
        else
        {
            int v=q.front();
            q.pop();
            q.push(v);
        }
        cnt++;
    }
    return 0;
}