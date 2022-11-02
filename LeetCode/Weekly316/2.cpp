#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int GCD(int a, int b)
    {
        if(!b)return a;
        return GCD(b, a%b);
    }
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            int gcd;
            if(nums[i]%k)
            for(int j=0;i+j<nums.size();j++)
            {
                if(!j)
                {
                    gcd=nums[i+j]; 
                }
                else
                {
                    gcd = GCD(max(gcd, nums[i+j]), min(gcd, nums[i+j]));
                }
                if(gcd==k)count++;
            }
        }       
        return count; 
    }
};

int main()
{
    Solution s;

    return 0;
}
