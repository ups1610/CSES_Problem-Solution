//Important use of segment tree class template and using difference array algorithm
//time complexity-> o(nlogn)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
template<class T> struct Seg {
	ll n;
	T ID = 0;
	vector<T> seg;
	T comb (T a, T b) {return a + b;}
	void init (ll _n) {n = _n; seg.assign(n * 2, ID);}
	void pull (ll p) {
		seg[p] = comb(seg[p * 2], seg[p * 2 + 1]);
	}
	void upd (ll i, T val) {
		seg[i+=n] += val;
		for (i /= 2; i; i /= 2) {
			pull(i);
		}
	}
	T query (int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra, seg[l++]);
			if (r&1) rb = comb(rb, seg[--r]);
		}
		return comb(ra, rb);
	}
};
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>v(n+1);
    Seg<ll>seg;
    seg.init(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        seg.upd(i,v[i]-v[i-1]);
    }
    while(m--)
    {
        ll x;
        cin>>x;
        if(x==1)
        {
            ll a,b,u;
            cin>>a>>b>>u;
            seg.upd(a,u);
            seg.upd(b+1,-u);
        }
        else
        {
            ll k;
            cin>>k;
            cout<<seg.query(1,k)<<endl;
        }
    }
    return 0;
}