#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <assert.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll norm(ll n, ll mod=MOD)
{
    return (n%mod+mod)%mod;
}

ll pwr(ll n, ll e, ll mod = MOD)
{
    ll a=1;
    while(e)
    {
        if(e&1)
        {
            a = norm(a*n);
        }
        n=norm(n*n);
        e/=2;
    }
    return a;
}

ll gcd(ll a, ll b)
{
    if(b>a)swap(a,b);
    if(!b)return a;
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const bool MULTI = true;

    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        vector<ll> arr(n),sm(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sm[0]=arr[0];
        for(int i=1;i<n;i++)sm[i]=sm[i-1]+arr[i];
        int cnt=0;
        priority_queue<ll> qp;
        ll inc=0;
        if(arr[m-1]>0)qp.push(arr[m-1]);
        for(int i=m-2;i>=0;i--)
        {
            while(sm[m-1]-inc>sm[i])
            {
                assert(!qp.empty());
                inc+=qp.top()*2ll;
                qp.pop();
                cnt++;
            }
            if(arr[i]>0)qp.push(arr[i]);
        }
        while(!qp.empty())qp.pop();
        inc=0;
        for(int i=m;i<n;i++)
        {
            if(arr[i]<0)qp.push(-1*arr[i]);
            while(sm[m-1]>sm[i]+inc)
            {
                assert(!qp.empty());
                inc+=qp.top()*2ll;
                qp.pop();
                cnt++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}