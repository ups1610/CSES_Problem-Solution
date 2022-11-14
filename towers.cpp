//approach is to check the upper_bound of next element to check wheather its greater is present multiset(beacause to encounter the dublicate element) then erase it otherwise add it.....
#include<bits/stdc++.h>
using namespace std;
 int main()
 {
     int n;
     cin>>n;
     vector<int>nums(n);
     for(int i=0;i<n;i++)
     {
         cin>>nums[i];
     }
     multiset<int>s;
     for(int i=0;i<n;i++)
     {
         auto it=s.upper_bound(nums[i]);
         if(it==s.end())
         s.insert(nums[i]);
         else{
         s.erase(it);
         s.insert(nums[i]);
         }
     }
     cout<<s.size()<<endl;
     return 0;
 }