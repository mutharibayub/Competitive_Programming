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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    for(int ttt = 1; ttt <= tttt; ttt++)
    {
        int m;
        cin >> m;
        ll lowest = 0; 
        ll highest = 0;
        map<ll, ll> get_at_min;
        map<ll, ll> get_at_max;
        for(int i = 0; i < m; i++) {
            ll n, l, r;
            cin >> n >> l >> r;
            lowest += l;
            highest += r;
            vector<pair<ll, ll>> t_arr(n);
            ll total = 0;
            for(auto &ele: t_arr) {
                cin >> ele.first;
            }
            for(auto &ele: t_arr) {
                cin >> ele.second;
                total += ele.second;
            }
            for(auto [num, cnt]: t_arr) {
                if(total-cnt < l) {
                    get_at_min[num] += l-(total-cnt);
                }
                if(cnt > total-r) {
                    get_at_max[num] += cnt - (total - r);
                }
            }
        }
        ll ans = 1e18;
        for(ll i = lowest; i <= highest && ans; i++) {
            ll to_reduce = get_at_max[i] - get_at_min[i];
            ll can_reduce = highest - i;
            ans = min(ans, get_at_min[i] + max(0ll, to_reduce - can_reduce));            
        }
        cout << ans << '\n';
    }
    return 0;
}