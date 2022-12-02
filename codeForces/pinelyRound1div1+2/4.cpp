#include <iostream>
#include <vector>
#include <map>
#include <array>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
const int N = 1e6+7;

ll norm(ll n)
{
    return (n%MOD+MOD)%MOD;
}

ll power(ll n, ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
        {
            ans*=n;
            ans%=MOD;
        }
        e/=2;
        n*=n;
        n%=MOD;
    }
    return ans;
}

void add(map<array<int,2>, ll> &obj, map<array<int,2>, ll> &other)
{
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    ll ans=0;
    return 0;
}