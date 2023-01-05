#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <array>

using namespace std; 

typedef long long ll;

const int N = 100+1;
const int MOD = 1e9+7;

ll fact[N];
ll factInv[N];
ll pow2[N];

ll norm(ll n)
{
    return (n%MOD+MOD)%MOD;
}

ll nCr(ll n, ll r)
{
    return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
}

ll pwr(ll n, ll e)
{
    ll ans=1;
    n=norm(n);
    while(e)
    {
        if(e&1)
        {
            ans=ans*n%MOD;
        }
        n=n*n%MOD;
        e/=2;
    }
    return ans;
}

ll getInv(ll n)
{
    return pwr(n, MOD-2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pow2[0]=1;
    fact[0]=1;
    for(int i=1;i<N;i++)
    {
        pow2[i]=pow2[i-1]*2%MOD;
        fact[i]=fact[i-1]*i%MOD;
    }
    factInv[N-1]=getInv(fact[N-1]);
    for(int i=N-2;i>=0;i--)
    {
        factInv[i]=factInv[i+1]*(i+1)%MOD;
    }

    const bool MULTI=true;

    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        int n,i,j,x,y;
        cin>>n>>i>>j>>x>>y;
        ll ans;
        if(x>y)
        {
            swap(x,y);
            i=n-i+1;
            j=n-j+1;
            swap(i,j);
        }
        if(i+n-j<x||n-i<n-x)
        {
            ans=0;
        }
        else if(y==n)
        {
            ans=nCr(x-1,i-1)*nCr(y-x-1,j-i-1)%MOD;
        }
        else
        {
            ans=0;
            int mid = j-i-1;
            int right = n-j-(x-i);
            if(mid-(n-y)>=0)
            {
                ans+=nCr(x-1,i-1)*pow2[n-y-1]%MOD*nCr(y-x-1,mid-(n-y))%MOD;
                ans=norm(ans);
            }
            if(right-(n-y)>=0)
            {
                ans+=nCr(x-1,i-1)*pow2[n-y-1]%MOD*nCr(y-x-1,right-(n-y))%MOD;
                ans=norm(ans);
            }
        }
        if(i==x&&j==y)ans=norm(ans-1); // cater for ascending order
        cout << ans << '\n';
    }

    return 0;
}