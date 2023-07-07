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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        a--,b--,c--;
        if(a>b)swap(a, b);
        int circleLength = 2*(b-a);
        if(circleLength-1<max({a,b,c}))
        {
            cout << -1 << '\n';
            continue;
        }
        cout << (c+b-a)%(2*(b-a))+1 << '\n';
    }    

    return 0;
}