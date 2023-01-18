#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <array>

using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int N = 300;
const int N2 = N*N;
const int MAX_NUM = 2*N2+1;

int dp[N+1][2*N2+2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const bool MULTI = false;

    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int offset = N2;
        dp[1][arr[1]+offset]=1;
        for(int i=2;i<n;i++)
        {
            for(int j=0;j<=MAX_NUM;j++)
            {
                int cnt = dp[i-1][j];
                int num = j-offset;
                if(arr[i]+num+offset<=MAX_NUM)dp[i][arr[i]+num+offset]=(dp[i][arr[i]+num+offset]+cnt)%MOD;
                if(arr[i]-num+offset>=0&&num)dp[i][arr[i]-num+offset]=(dp[i][arr[i]-num+offset]+cnt)%MOD;
            }
        }
        int ans = 0;
        for(int i=0;i<=MAX_NUM;i++)
        {
            ans=(ans+dp[n-1][i])%MOD;
        }
        cout << ans << '\n';
    }

    return 0;
}