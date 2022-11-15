#include <iostream>
#include <assert.h>

using namespace std;

typedef long long ll;

ll getInverse(ll b, ll mod)
{
    ll a=mod;
    ll T0=0, T1=1, T2, Q; 
    while(1)
    {
        Q=a/b;
        T2=(((T0-Q*T1)%mod)+mod)%mod;
        swap(a, b);
        b%=a;
        if(!b)break;
        T0=T1;
        T1=T2;
    }
    return T1;
}

ll power(ll n, ll e, ll m)
{
    ll a=1;
    while(e)
    {
        if(e&1)
        {
            a*=n;
            a%=m;
        }
        e/=2;
        n*=n;
        n%=m;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,d;
        cin>>a>>b>>d;
        
        // ll A=a, B=b, D=d;
        
        a |= b;
        if((a&-a) < (d&-d))
        {
            cout << -1 << '\n';
            continue;
        }
        d/=d&-d;
        
        ll a1=a, a2=0, m1=1<<30, m2=d;
        ll ans = a1+((((a2-a1)*getInverse(m1, m2)%m2)+m2)%m2)*m1;

        // assert((A|ans)%D==0);
        // assert((B|ans)%D==0);

        cout << ans << '\n';
    }


    return 0;
}