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
 
    vector<bool> possible(1e6+1,false);
    for(ll i=2;i<=1e6;i++)
    {
        ll start = 1+i+i*i;
        ll cur = i*i;
        while(start<=1e6)
        {
            cur*=i;
            possible[start]=true;
            start+=cur;
        }
    }
 
    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        cout << (possible[n]?"YES":"NO") << '\n';
    }    
 
    return 0;
}