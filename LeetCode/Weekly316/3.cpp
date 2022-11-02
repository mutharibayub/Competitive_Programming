#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    long long costC(vector<int>& nums, vector<int>& cost, int target)
    {
        long long c = 0;
        for(int i=0;i<nums.size();i++)
        {
            c += 1ll*abs(target-nums[i])*cost[i];
        }
        return c;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int minV=1e9+7, maxV = -1;
        for(int i=0;i<nums.size();i++)
        {
            minV= min(minV, nums[i]);
            maxV = max(maxV, nums[i]);
        }
        int target = minV;
        int jump = maxV-minV;
        long long minCost = costC(nums, cost, target);
        for(;jump;jump/=2)
        {
            long long tmp;
            while(target+jump<=maxV && (tmp=costC(nums, cost, target+jump)) < minCost)
            {
                target += jump;
                minCost = tmp;
            }
            while(target-jump>=minV && (tmp=costC(nums, cost, target-jump)) < minCost)
            {
                target -= jump;
                minCost = tmp;
            }
        }
        return minCost;
    }
};

int main()
{
    Solution s;

    return 0;
}
