#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll norm(ll num)
{
    return (num%MOD+MOD)%MOD;
}

ll power(ll n, ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
        {
            ans=norm(ans*n);
        }
        n=norm(n*n);
        e/=2;
    }
    return ans;
}

const int N = 1e6+7;
int sieve[N];
ll phi[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<N;i++)sieve[i]=i;
    for(int i=2;i<N;i++)
    {
        if(sieve[i]==i)
        for(ll j=1ll*i*i;j<N;j+=i)
        {
            sieve[j]=i;
        }
    }

    for(int i=2;i<N;i++)
    {
        set<int> pfs;
        int n = i;
        while(sieve[n]>1)
        {
            pfs.insert(sieve[n]);
            int d=sieve[n];
            while(n%d==0)n/=d;
        }
        phi[i]=i;
        for(auto pf:pfs)
        {
            phi[i]-=phi[i]/pf;
        }
    }

    for(int i=1;i<N;i++)phi[i]+=phi[i-1];

    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll score=0;
        for(ll k=n-1;k>=1;k--)
        {
            ll gcdVal = k+1;
            ll avl = phi[n/gcdVal];
            ll useUp = min(avl/k, m/k);
            score += useUp*(k+1);
            m -= useUp*k;
            if(!m)break;
        }
        if(m) cout << -1 << '\n';
        else cout << score << '\n';
    }

    return 0;
}