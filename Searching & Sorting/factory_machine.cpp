#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n,t;
    cin>>n>>t;
    vector<long long int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    long i=0,j=1e18;
    long ans=1e18;
    while(i<=j)
    {
        long mid=i+(j-i)/2;
        long product =0;
        for(int i=0;i<n;i++)
        {
            product+=min(mid/arr[i],(long long int)1e9);
        }
        if(product>=t)
        {
            ans=min(ans,mid);
            j=mid-1;
        }
        else 
        i=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}