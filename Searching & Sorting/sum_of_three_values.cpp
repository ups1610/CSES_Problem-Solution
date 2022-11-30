//we have to print position/index(unique) not value 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,x;
    cin>>n>>x;
    vector<pair<ll,ll>>v;
	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		pair<ll,ll> p; 
		p.first = a; 
		p.second = i;
		v.push_back(p);
	}
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        int j=0;
        int k=n-1;
        
        while(j!=k)
        {
            ll target=x-v[i].first;
            if(i!=j && i!=k && v[j].first+v[k].first==target)
            {
                cout<<v[i].second<<" "<<v[j].second<<" "<<v[k].second<<endl;
                return 0;
            }
           if(v[j].first+v[k].first<target)
            j++;
           else 
            k--;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}