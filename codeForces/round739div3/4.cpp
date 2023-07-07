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

int countMoves(const string& base, const string &target)
{
    int cnt=0;
    for(int i=0;i<base.size()&cnt<target.size();i++)
    {
        if(base[i]==target[cnt])cnt++;
    }
    return (base.size()-cnt) + (target.size()-cnt);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        int ans = 1e9+7;
        for(unsigned long long i=1;i<=(1ll<<62);i<<=1)
        {
            ans = min(ans, countMoves(to_string(n), to_string(i)));
        }
        cout << ans << '\n';
    }    

    return 0;
}