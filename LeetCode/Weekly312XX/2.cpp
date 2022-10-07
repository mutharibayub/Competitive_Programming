#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal=-1;
        for(int i=0;i<nums.size();i++)
        {
            maxVal = max(maxVal, nums[i]);
        }
        int maxLen = 1;
        int len = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maxVal)
            {
                len++;
            }
            else
            {
                len = 0;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};