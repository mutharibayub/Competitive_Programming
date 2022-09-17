//fenwick tree implementation of INVCNT
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int64_t getSum(const vector<int64_t>& fwt, int index)
{
    index++;
    int64_t sum = 0;
    while(index)
    {
        sum += fwt[index-1];
        index -= (index&-index);
    }
    return sum;
}

void update(vector<int64_t>& fwt, int index, int64_t newVal)
{
    int64_t diff = newVal - fwt[index];
    index++;
    while(index<=fwt.size())
    {
        fwt[index-1] += diff;
        index += index&-index;
    }
}

void testCase()
{
    int n;
    cin>>n;
    vector<int64_t> nums(n);
    vector<int64_t> fwt(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int64_t> sorted = nums;
    reverse(nums.begin(), nums.end());
    sort(sorted.begin(), sorted.end());
    int64_t inversionCount = 0;
    for(int i=0;i<n;i++)
    {
        int numIndex = lower_bound(sorted.begin(), sorted.end(), nums[i])-sorted.begin();
        update(fwt, numIndex, fwt[numIndex]+1);
        inversionCount += getSum(fwt, numIndex)-1;
    }
    cout<<inversionCount<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        testCase();
    }
}