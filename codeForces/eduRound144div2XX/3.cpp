#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 50;
const int MOD = 998244353;

ll fact[N];
ll factInv[N];

ll pwr(ll n, ll e)
{
    ll o = 1;n%=MOD;
    while(e)
    {
        if(e&1)o=o*n%MOD;
        n=n*n%MOD;
        e/=2;
    }return o;
}

ll getInv(ll n)
{
    return pwr(n, MOD-2);
}

ll nCr(ll n, ll r)
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
    for(int i=N-1;i>=1;i--)factInv[i-1]=i*factInv[i]%MOD;

    int t;
    cin>>t;
    while(t--)
    {
        int l, r;
        cin>>l>>r;
        int tmp = 1;
        int mx = 1;
        ll cnt = 0;
        while(tmp*2*l<=r)tmp*=2,mx++;
        int tc = 0;
        while(mx-1-tc>=0)
        {
            if(r/tmp<l)break;
            cnt = (cnt + (r/tmp-l+1) * nCr(mx-1, tc) % MOD) % MOD;
            tmp=tmp*3/2;
            tc++;
        }

        cout << mx << ' ' << cnt << '\n';

    }

    return 0;
}