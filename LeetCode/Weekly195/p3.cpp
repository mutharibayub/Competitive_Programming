#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numSubseq(vector<int>& nums, int target) {
    int s=0,l=nums.size()-1;
    vector<int> twoPwrs;
    sort(nums.begin(),nums.end());
    while(l-s>=0)
    {
        if(nums[l]+nums[s]<=target)
        {
            twoPwrs.push_back(l-s);
            s++;
        }
        else
        {
            l--;
        }
    }
    int64_t out = 0;
    int64_t val = 1;
    for(int i=twoPwrs.size()-1, cPwr=0;i>=0;i--)
    {
        while(cPwr<twoPwrs[i])
        {
            val=(val*2)%int64_t(1e9+7);
            cPwr++;
        }
        out += val;
        if(out>int64_t(1e9+7))
        {
            out%=int64_t(1e9+7);
        }
    }
    return out;
}

int main()
{
    vector<int> arr({27,21,14,2,15,1,19,8,12,24,21,8,12,10,11,30,15,18,28,14,26,9,2,24,23,11,7,12,9,17,30,9,28,2,14,22,19,19,27,6,15,12,29,2,30,11,20,30,21,20,2,22,6,14,13,19,21,10,18,30,2,20,28,22});
    int a=31;
    cout<<numSubseq(arr,a);
    return 0;
}