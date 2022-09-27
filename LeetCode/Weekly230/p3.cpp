#include <iostream>
#include <vector>
using namespace std;

int minOperations(vector<int>& nums1, vector<int>& nums2) {
    vector<int> num1Count(7,0);
    vector<int> num2Count(7,0);
    int num1Sum=0;
    int num2Sum=0;
    for(int i=0;i<nums1.size();i++)
    {
        num1Count[nums1[i]]++;
        num1Sum+=nums1[i];
    }
    for(int i=0;i<nums2.size();i++)
    {
        num2Count[nums2[i]]++;
        num2Sum+=nums2[i];
    }
    int sumDiff = abs(num1Sum-num2Sum);
    if(!sumDiff)return 0;
    for(int i=1;i<=6;i++)
    {
        num1Count[i] += num2Count[7-i];
    }
    int minSteps=0;
    for(int i=1;i<=5;i++)
    {
        if(num1Sum>num2Sum)
        {
            int numAvail = num1Count[7-i];
            int needed = (sumDiff+7-i-2)/(7-i-1);
            if(numAvail>=needed)
            {
                return minSteps+needed;
            }
            else
            {
                sumDiff -= numAvail*(7-i-1);
                minSteps+=numAvail;
            }
        }
        else
        {
            int numAvail = num1Count[i];
            int needed = (sumDiff+7-i-2)/(7-i-1);
            if(numAvail>=needed)
            {
                return minSteps+needed;
            }
            else
            {
                sumDiff -= numAvail*(7-i-1);
                minSteps+=numAvail;
            }
        }
    }
    if(sumDiff>0)return -1;
    return minSteps;
}

int main()
{

    return 0;
}