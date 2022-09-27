#include <iostream>
#include <vector>
#include <Algorithm>
#include <list>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    int pivotCount = 0;
    list<int> prePivot;
    list<int> postPivot;
    vector<int> outArr;
    outArr.reserve(nums.size());
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]<pivot)
        {
            prePivot.push_back(nums[i]);
        }
        else if(nums[i]>pivot)
        {
            postPivot.push_back(nums[i]);
        }
        else
        {
            pivotCount++;
        }
    }   
    for(auto iter = prePivot.begin();iter!=prePivot.end();iter++)
    {
        outArr.push_back(*iter);
    }
    for(int i=0;i<pivotCount;i++)
    {
        outArr.push_back(pivot);
    }
    for(auto iter = postPivot.begin();iter!=postPivot.end();iter++)
    {
        outArr.push_back(*iter);
    }
    return outArr;
}

int main()
{
    int num = 0;
    

    return 0;
}