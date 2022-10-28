//Leetcode->https://leetcode.com/problems/minimum-cost-to-make-array-equal/
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        long long sum=0;
        for(int i=0;i<v.size();i++)
        {
            sum+=1LL*v[i].second;
        }
        long long sz=(sum%2==0)?(sum)/2:(sum+1)/2;
        long long total=0;
        int i=0;
        long long median=0;
        while(total<sz && i<nums.size())
        {
            total+=1ll*v[i].second;
            median=v[i].first;
            i++;
        }
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=abs(1ll*nums[i]-median)*(1ll*cost[i]);
        }
        return ans;
    }
};