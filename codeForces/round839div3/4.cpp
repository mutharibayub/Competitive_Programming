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
        int mn = 0, mx = 1e9;
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i+1<n&&mn!=-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int mid = (arr[i]+arr[i+1]+1)/2;
                mn=max(mn, mid);
            }
            else if(arr[i]<arr[i+1])
            {
                int mid = (arr[i]+arr[i+1])/2;
                mx=min(mx, mid);
            }
            if(mx<mn)
            {
                mn=-1;
                break;
            }
        }
        cout << mn << '\n';
    }

    return 0;
}