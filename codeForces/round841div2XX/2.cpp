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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans = 0;
        ans += norm(norm(norm(n*(n+1))*(2*n+1))*power(6,MOD-2));
        n--;
        ans += norm(norm(norm(n*(n+1))*(2*n+1))*power(6,MOD-2));;
        ans += norm(n*(n+1)/2);
        ans = norm(ans);
        ans = norm(ans*2022);
        cout << ans << '\n';        
    }

    return 0;
}