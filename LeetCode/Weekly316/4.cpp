#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end(), [](int a, int b){return a%2<b%2 || (a%2==b%2 && a<b);});
        sort(target.begin(), target.end(), [](int a, int b){return a%2<b%2 || (a%2==b%2 && a<b);}); 
        long long count = 0;
        for(int i=0;i<nums.size();i++)
        {
            count += abs((nums[i]-target[i])/2);
        }
        return count/2;
    }
};

int main()
{
    Solution s;

    return 0;
}
