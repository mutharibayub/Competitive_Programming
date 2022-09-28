#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int64_t> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    unordered_map<int64_t, int64_t> c1,c2;
    int64_t maxVal = -1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                c1[arr[i]*arr[j]+arr[k]]++;
                if(arr[k])
                c2[(arr[i]+arr[j])*arr[k]]++;           
            }
        }
    }
    int64_t count=0;
    for(auto it:c1)
    {
        count += it.second*c2[it.first];
    }
    cout << count << '\n';
    return 0;
}