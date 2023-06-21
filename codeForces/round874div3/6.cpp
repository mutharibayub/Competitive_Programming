#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll pwr(ll n, ll e)
{
    ll out=1;
    while(e)
    {
        if(e&1)
        {
            out=(out*n)%MOD;
        }n=(n*n)%MOD,e>>=1;
    }return out;
}

ll getInv(ll n)
{
    return pwr(n, MOD-2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.begin(), arr.end());
        vector<pair<int,ll>> narr;
        for(int i=0;i<n;i++)
        {
            if(narr.empty()||narr.back().first!=arr[i])
            {
                narr.push_back({arr[i],1});
            }
            else
            {
                narr.back().second++;
            }
        }
        vector<pair<ll,ll>> mul(narr.size());
        mul[0].first=narr[0].second;
        for(int i=1;i<narr.size();i++)mul[i].first=(narr[i].second*mul[i-1].first)%MOD;
        mul.back().second = getInv(mul.back().first);
        for(int i=narr.size()-2;i>=0;i--)mul[i].second=(mul[i+1].second*narr[i+1].second)%MOD;
        ll ans = 0;
        for(int i=0;i+m-1<narr.size();i++)
        {
            if(narr[i+m-1].first-narr[i].first==m-1)
            {
                ll mult = (mul[i+m-1].first*(i?mul[i-1].second:1))%MOD;
                ans = (ans+mult)%MOD;
            }
        }
        cout << ans << '\n';
    }
     
    return 0;
}