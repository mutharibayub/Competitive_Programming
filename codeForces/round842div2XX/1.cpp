#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD=1e9+7;

ll pwr(ll n, ll e, ll mod=MOD)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
        {
            ans=ans*n%mod;
        }
        n=n*n%mod;
        e/=2;
    }
    return ans;
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
        int n;
        cin>>n;
        cout << (n-1) << '\n';
    }

    return 0;
}