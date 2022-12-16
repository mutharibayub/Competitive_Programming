#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

const int MAX_VAL = 1e7+1;

int sieve[MAX_VAL];

ll GCD(ll x,ll y)
{
    if(x<y)swap(x,y);
    if(!y)return x;
    return GCD(y,x%y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<MAX_VAL;i++)
    {
        sieve[i]=i;
    }
    for(int i=2;i<MAX_VAL;i++)
    {
        if(sieve[i]==i)
        {
            for(int j=i+i;j<MAX_VAL;j+=i)
            {
                sieve[j]=i;
            }
        }
    }

    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        if(n%2==m%2)
        {
            if(GCD(n,m)==1)
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else
        {
            ll diff=m-n;
            if(diff==1)
            {
                cout << -1 << '\n';
                continue;
            }
            set<ll> pfs;
            while(sieve[diff]!=diff)
            {
                pfs.insert(sieve[diff]);
                diff/=sieve[diff];
            }
            if(sieve[diff]>1)pfs.insert(sieve[diff]);
            ll ans=1e15+7;
            for(auto pf:pfs)
            {
                ll v = (((n-1)/pf)+1)*pf;
                ans = min(ans, v-n);
            }
            cout << ans << '\n';
        }
    }


    return 0;
}