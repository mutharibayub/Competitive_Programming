#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>

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
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        ll ans = 0;
        for(int bit=0;bit<30;bit++)
        {
            for(int i=0;i<n;)
            {
                int count = 0;
                while(arr[i]&(1<<bit) && i<n)
                {
                    i++;
                    count++;
                }
                ans += (1ll<<bit)*(count*1ll*(count+1))/2;
                while(!(arr[i]&(1<<bit)) && i<n)
                {
                    i++;
                }                
            }
            // cout << bit << ": " << ans << '\n';
        }
        cout << ans << '\n';
    }


    return 0;
}