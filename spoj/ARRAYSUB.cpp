#include <iostream>
#include <vector>

using namespace std;

const int blockSize = 1e3;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> maxes;
    for(int i=0;i<n;)
    {
        maxes.push_back(0);
        for(int j=0;j<blockSize&&i+j<n;j++,i++)
        {
            maxes.back() = max(maxes.back(), arr[i]);
        }
    }
    int k;
    cin>>k;
    for(int i=0;i+k<=n;i++)
    {
        int s = i, e = i+k, val=-1;
        for(int j=s;j<e;)
        {
            if((j+blockSize<e || (j+blockSize>n && e==n)) && j%blockSize==0)
            {
                val = max(val, maxes[j/blockSize]);
                j+=blockSize;
            }
            else
            {
                val = max(val, arr[j]);
                j++;
            }
        }
        if(i)cout << ' ';
        cout << val;
    }
    cout << '\n';
    return 0;
}