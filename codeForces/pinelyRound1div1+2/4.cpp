#include <iostream>
#include <vector>
#include <map>
#include <array>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
const int N = 1e6+7;
ll fact[N];
ll factInv[N];

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

ll nCr(ll n, ll r)
{
    return norm(norm(fact[n]*factInv[n-r])*factInv[r]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=norm(fact[i-1]*i);
    }
    factInv[N-1]=power(fact[N-1],MOD-2);
    for(int i=N-2;i>=0;i--)
    {
        factInv[i]=norm(factInv[i+1]*(i+1));
    }

    int n,k;
    cin>>n>>k;
    ll ans=0;
    for(int q=0;q<n;q++)
    {
        ans+=norm(norm(power(3, n-q)*nCr(k-1, q/2-1))*nCr(n-k, (q+1)/2-1));
        ans=norm(ans);
    }
    cout << ans << '\n';
    return 0;
}