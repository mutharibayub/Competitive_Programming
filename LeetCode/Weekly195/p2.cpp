#include <iostream>
#include <vector>
using namespace std;

bool canArrange(vector<int>& arr, int k) {
    int kVals[100000];
    for(int i=0;i<100000;i++)
    {
        kVals[i]=0;
    }
    for(int i=0;i<arr.size();i++)
    {
        int temp = arr[i]%k;
        if(temp<0)
        {
            kVals[temp+k]++;
        }
        else
        {
            kVals[temp]++;
        }
    }
    if(kVals[0]%2!=0){return false;}
    for(int i=1;i<=k/2;i++)
    {
        if(kVals[i]!=kVals[k-i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> a({1,2,3,4,5,6});
    int k=7;
    cout<<canArrange(a,k);
    return 0;
}