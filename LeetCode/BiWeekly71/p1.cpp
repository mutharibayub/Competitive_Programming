#include <iostream>
#include <vector>
#include <Algorithm>
using namespace std;

int minimumSum(int num) {
    vector<int> nums;
    for(int i=0;i<4;i++)
    {
        nums.push_back(num%10);
        num/=10;
    }    
    sort(nums.begin(),nums.end());
    int num1 = nums[0]*10 + nums[2];
    int num2 = nums[1]*10 + nums[3];
    return num1+num2;
}

int main()
{
    int num = 0;
    

    return 0;
}