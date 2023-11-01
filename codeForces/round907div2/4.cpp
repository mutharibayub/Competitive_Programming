#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

vector<pair<pair<ll, ll>, ll>> getRanges(ll l, ll r, ll b)
{
    vector<pair<pair<ll, ll>, ll>> rngs; 
    int exp = -1;
    ll val = 1;
    ll mn = 0;
    ll mx = val-1;
    while(mn <= r)
    {
        rngs.push_back({{mn, mx}, exp});
        mn = mx+1;
        if(r/val < b)
        {
            val = r+1;
        }
        else
        {
            val *= b;
        }
        mx = val-1;
        exp++;
    }
    vector<pair<pair<ll, ll>, ll>> out;
    for(auto rng: rngs)
    {
        if(rng.first.second < l)
            continue;
        if(rng.first.first < l)
        {
            out.push_back({{l, rng.first.second}, rng.second});
            continue;
        }
        out.push_back(rng);
    }
    return out;
}

const int MOD = 1e9+7;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<pair<ll, ll>, ll> dp;
    auto rngs = getRanges(0, 1e18, 2);
    for(auto rng: rngs)
    {
        ll sum = 0;
        if(rng.first.second < 4)
            continue;
        auto rrngs = getRanges(rng.first.first, rng.first.second, rng.second);
        for(auto rrng: rrngs)
        {
            ll count = rrng.first.second - rrng.first.first + 1;
            count %= MOD;
            count *= rrng.second;
            count %= MOD;
            sum += count;
            sum %= MOD;
        }
        dp[{rng.first.first, rng.first.second}] = sum;
    }

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        ll l, r;
        cin >> l >> r;

        ll ans = 0;
        auto rngs = getRanges(l, r, 2);
        for(auto rng: rngs)
        {
            if(dp.find(rng.first) != dp.end())
            {
                ans += dp[rng.first];
                ans %= MOD;
                continue;
            }
            auto rrngs = getRanges(rng.first.first, rng.first.second, rng.second);
            for(auto rrng: rrngs)
            {
                ll count = rrng.first.second - rrng.first.first + 1;
                count %= MOD;
                count *= rrng.second;
                count %= MOD;
                ans += count;
                ans %= MOD;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}