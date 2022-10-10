#include <iostream>

using namespace std;

#define ll long long

ll nCr(ll n, ll r)
{
    ll n_1 = n-1;
    n = n+r-1;
    ll smaller = min(n_1, r);
    ll larger = max(n_1, r);
    ll ans = 1;
    ll div = 2;
    for(ll i=n;i>larger;i--)
    {
        ans*=i;
        while(div<=smaller && ans%div==0)
        {
            ans/=div;
            div++;
        }
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
        int n,r;
        cin>>n>>r;
        if(n==r)cout << "1\n";
        else cout << nCr(r, n-r) << '\n';
    }


    return 0;
}