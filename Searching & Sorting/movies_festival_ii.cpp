//extended version of movies_festival(easy) problem 
//in this consider extra use of set with lowerbound 

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool static cmp(pair<int,int>&a,pair<int,int>&b)
{
    if(a.second<b.second)
    return a.second<b.second;
    else
    return b.second>a.second;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>nums;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        nums.push_back({a,b});
    }
    int cnt=0;
    sort(nums.begin(),nums.end(),cmp);
    set<pair<int,int>>s;
    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
        {
            s.insert({-1*(nums[i].second),i});
            cnt++;
        }
        else
        {
            auto it=s.lower_bound({-1*nums[i].first,-1});
            if(it==s.end() && s.size()<k)
            {
                s.insert({-1*nums[i].second,i});
                cnt++;
            }
            else if(it!=s.end())
            {
                s.erase(it);
                s.insert({-1*nums[i].second,i});
                cnt++;
            }
        }
        
        
    }
    cout<<cnt<<endl;
    return 0;
}