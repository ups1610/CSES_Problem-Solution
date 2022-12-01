// we have to just think of max time to read a book and under which all other books have been covered
// one ans is sum of all books min time to read each book
// another case is- if someone waiting for another book to finish (max time taking book) then we get 2*max time is ans

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    
    ll mx=*max_element(v.begin(),v.end());
    int i=0,j=mx;
    
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
    }
    cout<<max(sum,2*mx)<<endl;
    return 0;
}