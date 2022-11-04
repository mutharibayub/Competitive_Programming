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
        vector<int> arr(n+1);
        vector<bool> dp(n+1, false);
        for(int i=1;i<=n;i++)cin>>arr[i];
        dp[0]=true;
        for(int i=1;i<=n;i++)
        {
            if(i-arr[i]-1>=0 && dp[i-arr[i]-1])
            {
                dp[i]=true;
            }
            if(dp[i-1] && i+arr[i]<=n)
            {
                dp[i+arr[i]]=true;
            }
        }
        cout << (dp[n]?"YES":"NO") << '\n';
    }

    return 0;
}
