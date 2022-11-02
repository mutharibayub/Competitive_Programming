#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.begin(), arr.end());
        ll ans = 0;
        for(int i=1;i<n-1;i++)
        {
            ans = max(ans, arr[i]-arr[i-1]+arr[n-1]-arr[i-1]);
        }
        for(int i=n-2;i>=1;i--)
        {
            ans = max(ans, arr[i+1]-arr[i]+arr[i+1]-arr[0]);
        }
        cout << ans << '\n';
    }

    return 0;
}