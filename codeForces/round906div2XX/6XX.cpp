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
    while(tttt--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int, int>> rngs(m);
        for(int i = 0; i < m; i++) {
            cin >> rngs[i].first >> rngs[i].second;
            rngs[i].first--, rngs[i].second--;

        }
        sort(rngs.begin(), rngs.end());
        minPQ<int> cur_rngs;
        rngs.push_back({n, n});
        m = rngs.size();
        int l_idx = 0;
        vector<pair<int, pair<int, int>>> dp_rngs;
        for(int i = 0; i < n; i++) {
            while(l_idx < m && rngs[l_idx].first <= i) {
                cur_rngs.push(rngs[l_idx++].second);
            }
            while(!cur_rngs.empty() && cur_rngs.top() < i) {
                cur_rngs.pop();
            }
            int l = i;
            for(int j = 0; j + (int)cur_rngs.size() <= k && l_idx + j < m; j++) {
                int r = rngs[j+l_idx].first - 1;
                if(l > r) {
                    continue;
                }
                dp_rngs.push_back({j + (int)cur_rngs.size(), {l, r}});
            }
        }
        sort(dp_rngs.begin(), dp_rngs.end(), 
            [&](const auto &l, const auto &r) {
                return l.second < r.second;
            }
        );
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for(int i = 0; i < dp_rngs.size(); i++) {
            int l = dp_rngs[i].second.first;
            if(l) { // only works since l will have all values from 0 to n-1
                for(int j = 0; j <= k; j++) {
                    dp[l][j] = max(dp[l][j], dp[l-1][j]);
                }
            }
            int r = dp_rngs[i].second.second + 1;
            int cnt = r - l;
            int used = dp_rngs[i].first;
            for(int j = 0; j+used <= k; j++) {
                dp[r][j+used] = max(dp[r][j+used], dp[l][j] + cnt);
                ans = max(ans, dp[r][j+used]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}