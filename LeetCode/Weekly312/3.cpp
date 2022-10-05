#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> less(nums.size(),0);
        vector<int> more(nums.size(),0);
        for(int i=0;i<nums.size()-1;i++)
        {
            less[i+1] = less[i];
            more[i+1] = more[i];
            if(nums[i+1]<nums[i])
            {
                less[i+1]++;
            }
            if(nums[i+1]>nums[i])
            {
                more[i+1]++;
            }
        }
        // for(int i=0;i<less.size();i++)
        // {
        //     cout << less[i] << ' ';
        // }cout << '\n';
        // for(int i=0;i<more.size();i++)
        // {
        //     cout << more[i] << ' ';
        // }cout << '\n';
        vector<int> ans;
        for(int i=k;i<nums.size()-k;i++)
        {
            if(more[i-1]-more[i-k] || less[i+k]-less[i+1])continue;
            ans.push_back(i);
        }
        return ans;
    }
};