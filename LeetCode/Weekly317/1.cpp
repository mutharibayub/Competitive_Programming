#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%6==0)
            {
                sum += nums[i];
                count ++;
            }
        }    
        if(!count)return count;
        return sum/count;    
    }
};

int main()
{
    return 0;
}
