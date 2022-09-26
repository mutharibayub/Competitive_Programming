#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin>>n)
    {
        vector<int> arr(n);
        vector<vector<array<int64_t,2>>> dp(n, vector<array<int64_t,2>>(n));
        for(int i=0;i<n;i++)
        {
            cin >> dp[i][i][0];
            dp[i][i][1] = 0;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j+i<=n;j++)
            {
                dp[j][j+i-1] = {-1,(int)1e9+7};
                for(int c=1;c<i;c++)
                {
                    dp[j][j+i-1][0] = (dp[j][j+c-1][0]+dp[j+c][j+i-1][0])%100;
                    dp[j][j+i-1][1] = min(dp[j][j+i-1][1],dp[j][j+c-1][0]*dp[j+c][j+i-1][0]+dp[j+c][j+i-1][1]+dp[j][j+c-1][1]);
                }
            }
        }
        cout << dp[0][n-1][1] << endl;
    }

    return 0;
}