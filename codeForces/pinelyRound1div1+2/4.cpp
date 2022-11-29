#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
const int N = 1e6+7;

ll dp[N][2];

ll norm(ll n)
{
    return (n%MOD+MOD)%MOD;
}

ll power(ll n, ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
        {
            ans*=n;
            ans%=MOD;
        }
        e/=2;
        n*=n;
        n%=MOD;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=0;i<n;i++)dp[i][0]=dp[i][1]=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=norm(dp[i][1]+dp[i-1][0]);
        dp[i][1]=norm(3*dp[i][1]+dp[i-1][1]);
        dp[i][0]=norm(3*dp[i][1]+dp[i-1][0]);
        dp[i][0]=norm(dp[i][1]+dp[i-1][1]);
        ans+=norm(dp[i][1]*power(2,n-i-1));
    }
    cout << ans << '\n';


    return 0;
}