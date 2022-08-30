#include <iostream>
#include <vector>
using namespace std;

int64_t mergeSort(vector<int64_t>& arr, int s, int e)
{
    if(e-s<=1)
    {
        return 0;
    }
    else
    {
        int64_t inversionCount = 0;
        int midPoint = (s+e)/2;
        inversionCount += mergeSort(arr, s, midPoint) + mergeSort(arr, midPoint, e);
        int i=0,j=0;
        vector<int64_t> left(midPoint - s);
        for(int a=s;a<midPoint;a++)
        {
            left[a-s] = arr[a];
        }
        vector<int64_t> right(e - midPoint);
        for(int a=midPoint;a<e;a++)
        {
            right[a-midPoint] = arr[a];
        }
        while(i+j < e-s)
        {
            if(j>=right.size())
            {
                arr[s+i+j] = left[i];
                i++;
            }
            else if(i>=left.size())
            {
                arr[s+i+j] = right[j];
                j++;
            }
            else if(left[i] > right[j])
            {
                arr[s+i+j] = right[j];
                j++;
                inversionCount+=left.size()-i;
            }
            else
            {
                arr[s+i+j] = left[i];
                i++;
            }
        }
        return inversionCount;
    }
}


void testCase()
{
    int n;
    cin>>n;
    vector<int64_t> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<mergeSort(arr, 0, arr.size())<<'\n';
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