#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

ll pwr(ll n, ll e, ll mod=MOD)
{
    n%=mod;
    ll ans=1;
    while(e)
    {
        if(e%2)ans=(ans*n)%mod;
        n=(n*n)%mod;
        e/=2;
    }
    return ans;
}

ll getInv(ll n, ll mod=MOD)
{
    return pwr(n, mod-2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string a,b;
        cin>>n>>a>>b;
        int diffCount=0;
        for(int i=0;i<n;i++)diffCount+=(a[i]!=b[i]);
        vector<ll> left(n+1);
        left[n]=1;
        ll nInv = getInv(n);
        for(int i=n-1;i>=0;i--)
        {
            ll lp=1ll*i*nInv%MOD;
            ll rp=((1-lp)%MOD+MOD)%MOD;
            left[i]=(lp+rp+(rp*left[i+1])%MOD)%MOD*getInv(lp)%MOD;
        }
        ll ans=0;
        for(int i=0;i<=diffCount;i++)
        {
            ans=(ans+left[i])%MOD;
        }
        cout << ans << '\n';
    }

    return 0;
}