//kadane Algorithm
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
        cin>>v[i];
    ll max_sum=INT_MIN,cur_sum=0;
    for(int i=0;i<n;i++)
    {
        cur_sum+=v[i];
        if(cur_sum>max_sum)
        max_sum=cur_sum;
        if(cur_sum<0)
        cur_sum=0;
    }
    cout<<max_sum<<endl;  
    return 0;  
}