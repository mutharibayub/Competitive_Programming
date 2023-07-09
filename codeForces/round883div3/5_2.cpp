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
 
bool canDo(int exp, ll n)
{
    ll l=2;
    ll h=1e9;
    while(l<=h)
    {
        ll mid = (l+h)/2;
        ll sm = 1+mid+mid*mid;
        if(sm<n)l=mid+1;
        else if(sm==n)return true;
        else h=mid-1;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    set<ll> possible;
    for(ll i=2;i<=1e6;i++)
    {
        ll start = 1+i+i*i;
        ll cur = i*i;
        while(start<=1e18)
        {
            possible.insert(start);
            if(ll(1e18)/cur>=i)cur*=i;
            else break;
            start+=cur;
        }
    }
    
    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        ll n;
        cin>>n;
        if(possible.find(n)!=possible.end() || canDo(2, n))
        {
            cout << "YES" << '\n';
            continue;
        }
        cout << "NO" << '\n';
    }    
 
    return 0;
}