#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k, count=0;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.begin(), arr.end());
        int i=0, j=n-1;
        while(j>=i)
        {
            if(arr[j]>=k)
            {
                count++;
                j--;
            }
            else if(i!=j && arr[i]+arr[j]>=k)
            {
                count++;
                i++, j--;
            }
            else
            {
                i++;
            }
        }
        cout << count << '\n';
    }

    return 0;
}