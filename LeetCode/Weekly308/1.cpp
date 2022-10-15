#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.rbegin(), nums.rend());
        int64_t sum = 0;
        for(auto num:nums)sum+=num;
        for(auto query:queries)
        {
            int64_t tmp = sum;
            int len = nums.size();
            for(int i=0;tmp>query;i++)
            {
                tmp -= nums[i];
                len--;
            }
            ans.push_back(len);
        }      
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}