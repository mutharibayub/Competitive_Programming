#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int64_t sum = 0;

        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int i=0, j=0;
        unordered_map<int, int> counts;
        int mask;
        for(int i=0;i<n;i++)
        {
            counts.clear();
            mask = arr[i];
            counts[arr[i]]++;
            sum+=mask;
            for(int j=i+1;j<n;j++)
            {
                counts[arr[j]]++;
                mask &= arr[j];
                if(!mask)
                {
                    while(!mask)
                    {
                        counts[arr[i]]--;
                        if(!counts[arr[i]])
                        {
                            mask = mask ^ arr[i];
                        }
                        i++;
                    }
                } 
            }
        }
    }


    return 0;
}