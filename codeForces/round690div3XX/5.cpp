#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 2e5+1;
const int MOD = 1e9+7;

ll fact[N];
ll factInv[N];
ll dp[N];

ll pwr(ll n, ll e)
{
    n%=MOD;
    ll ans=1;
    while(e)
    {
        if(e&1)ans=(ans*n)%MOD;
        e/=2, n=(n*n)%MOD;
    }
    return ans;
}

ll getInv(ll n)
{
    return pwr(n, MOD-2);
}

ll ncr(ll n, ll r)
{
    return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=fact[i-1]*i%MOD;
    factInv[N-1]=getInv(fact[N-1]);
    for(int i=N-2;i>=0;i--)factInv[i]=factInv[i+1]*(i+1)%MOD;

    int t;
    cin>>t;
    while(t--)
    {
        int n, m=3, k=2;
        cin>>n>>m>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        if(m==1)
        {
            cout << n << '\n';
            continue;
        }
        sort(arr.begin(), arr.end());
        for(int i=0;i<n-m+1;i++)
        {
            dp[i]=ncr(m-2+i,i);
        }
        ll ans = 0;
        for(int i=1;i<n-m+1;i++)dp[i]=(dp[i]+dp[i-1])%MOD;
        for(int i=0;i+m-1<n;i++)
        {
            auto it = --lower_bound(arr.begin(), arr.end(), arr[i]+k+1);
            int r = it-arr.begin();
            if(r-i+1<m)continue;
            int extra = r-i+1-m;
            ans = (ans+dp[extra])%MOD;
        }
        cout << ans << '\n';
    }

    return 0;
}