#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll pwr(ll n, ll e)
{
    ll o=1;
    while(e)
    {
        if(e%2)o=o*n%MOD;
        e/=2;
        n=n*n%MOD;
    }return o;
}

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

bool check(ll num, ll done, ll total)
{
    ll base = num+done*20;
    return 20*(total-done) >= base;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        ll s, k;
        cin>>s>>k;

        ll ans = s*k;
        while(s%10!=0&&s%10!=2)
        {
            s+=s%10;
            k--;
            ans=max(ans, s*k);
        }

        if(s%10==2)
        {
            ll mx = k/4;
            ll cur = 0;
            for(ll jmp=mx;jmp;jmp/=2)
            {
                while(cur+jmp<=mx && check(s, cur+jmp, mx))cur+=jmp;
            }
            s+=20*cur;
            k-=4*cur;
            ans = max(ans, s*k);
            for(int i=0;i<4&&k;i++)
            {
                s+=s%10;
                k--;
                ans=max(ans, s*k);
            }
        }

        cout << ans << '\n';
    }    

    return 0;
}