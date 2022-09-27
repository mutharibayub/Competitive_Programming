#include <iostream>
#include <vector>
#include <Algorithm>
using namespace std;

long long minimumDifference(vector<int>& nums) {
    vector<int64_t> sums(nums.size(), 0);
    int64_t sum = 0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        sums[i] = sum;
    }
    int size = nums.size()/3;
    int64_t minDiff = 1e17;
    for(int i=0;i<nums.size()-size;i++)
    {
        int64_t arrSum = sums[i+size-1]-(i?sums[i-1]:0);
        int64_t sum1,sum2;
        if(i>=size)
        {
            sum1 = sums[size-1];
            sum2 = sums[sums.size()-1] - sums[size-1] - arrSum; 
        }
        else
        {
            sum1 = sums[2*size-1] - arrSum;
            sum2 = sums[sums.size()-1] - sums[2*size-1] ; 
        }
        if (sum1-sum2<minDiff)
        {
            minDiff = sum1-sum2;
        }
    }
    return minDiff;
}

int main()
{
    vector<int> arr({7,9,5,8,1,3});
    cout<<minimumDifference(arr);

    return 0;
}