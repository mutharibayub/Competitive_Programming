#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <assert.h>
#include <array>

using namespace std;

typedef long long ll;

ll n=0,MOD=1;
const int N=1e6+1;
const int N3=N*3;
ll fact[N3];
ll factInv[N3];

ll norm(ll n, ll mod=MOD)
{
    return (n%mod+mod)%mod;
}

ll ncr(ll n, ll r)
{
    return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
}

ll pwr(ll n, ll e, ll mod=MOD)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
        {
            ans=ans*n%mod;
        }
        n=n*n%mod;
        e/=2;
    }
    return ans;
}

ll getInverse(ll n, ll mod=MOD)
{
    return pwr(n, mod-2, mod);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>MOD;
    
    fact[0]=1;
    for(int i=1;i<=3*n;i++)
    {
        fact[i]=fact[i-1]*i%MOD;
    }
    factInv[3*n]=getInverse(fact[3*n]);
    for(int i=3*n-1;i>=0;i--)
    {
        factInv[i]=factInv[i+1]*(i+1)%MOD;
    }

    ll pt[4]={1,norm(2*fact[2*n]-fact[n]),2*ncr(2*n,n)%MOD*fact[n]%MOD*fact[2*n]%MOD,fact[3*n]};

    for(int i=0;i<=n;i++)
    {
        pt[2]-=ncr(n,n-i)*ncr(n,i)%MOD*ncr(2*n-i,n)%MOD*fact[n]%MOD*fact[n]%MOD*fact[n]%MOD;
        pt[2]=norm(pt[2]);
    }

    for(int i=3;i>0;i--)
    {
        pt[i]-=pt[i-1];
        pt[i]=norm(pt[i]);
    }

    ll ans=0;
    for(int i=0;i<4;i++)
    {
        ans+=i*pt[i]%MOD;
        ans%=MOD;
    }
    cout << ans << '\n';

    return 0;
}