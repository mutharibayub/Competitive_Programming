#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 20+1;

ll fact[N];

ll nCr(ll n, ll r)
{
    return fact[n]/fact[n-r]/fact[r];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=fact[i-1]*i;
    }

    int n;
    cin>>n;
    ll ans = nCr(n, n/2)/2*fact[n/2-1]*fact[n/2-1];
    cout << ans << '\n';

    return 0;
}