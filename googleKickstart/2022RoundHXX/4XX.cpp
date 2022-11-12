#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;

const int N = 1e5+1;

ll dp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            arr[i]--;
        }
        vector<int> cycleLengths;
        vector<bool> done(n, false);
        for(int i=0;i<n;i++)
        {
            int n=arr[i];
            int len=0;
            while(!done[n])
            {
                done[n]=true;
                n = arr[n];
                len++;
            }
            if(len)cycleLengths.push_back(len);
        }
        sort(cycleLengths.rbegin(), cycleLengths.rend());
        vector<int> dp(n+1,1e9+7);

        dp[0]=-1;
        for(int i=0;i<cycleLengths.size();i++)
        {
            int len = cycleLengths[i];
            for(int j=n;j>=0;j--)
            {
                if(j+len>n)continue;
                dp[j+len]=min(dp[j+len], dp[j]+1);
            }
        }
        int minVal = 1e9+7;
        for(int i=n;i>=1;i--)
        {
            dp[i] = min(dp[i], minVal+1);
            minVal = min(minVal, dp[i]);
        }

        cout << "Case #" << t << ":";
        for(int i=1;i<=n;i++)
        {
            cout << ' ' << dp[i];
        }
        cout << '\n';
    }   


    return 0;
}