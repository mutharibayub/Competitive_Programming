#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask = nums[0];
        int l=0,r=0;
        int longestLen = 1;
        for(int i=1;i<nums.size();i++)
        {
            r++;
            while(l!=r && mask&nums[i])
            {
                mask = mask^nums[l++];
            }
            mask = mask|nums[i];
            longestLen = max(longestLen, r-l+1);
        }        
        return longestLen;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}