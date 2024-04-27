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
#include <string>

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
        int n;
        cin >> n;
        vector<vector<int>> al(n);
        for(int i = 1; i < n; i++) {
            int u;
            cin >> u;
            --u;
            al[u].push_back(i);
            al[i].push_back(u);
        }
        string s;
        cin >> s;
        vector<int> parent(n, -1);
        auto inf = (ll) 1e9;
        vector<array<ll, 3>> dp(n, array<ll, 3>({inf, inf, inf})); // C S P
        auto dfs = [&](auto self, int u) -> void {
            int child_count = 0;
            for(auto v: al[u]) {
                if (v == parent[u]) {
                    continue;
                }
                parent[v] = u;
                child_count++;
                self(self, v);
            }
            if (s[u] == 'C') {
                dp[u] = {0, 0, 0};
            } else if(s[u] == 'S') {
                dp[u] = {inf, 0, inf};
            } else {
                dp[u] = {inf, inf, 0};
            }
            if (child_count) {
                for(auto v: al[u]) {
                    if (v == parent[u]) {
                        continue;
                    }
                    dp[u][0] += min({dp[v][0], dp[v][1]+1, dp[v][2]+1});
                    dp[u][1] += min({dp[v][0], dp[v][1], dp[v][2]+1});
                    dp[u][2] += min({dp[v][0], dp[v][1]+1, dp[v][2]});
                }
            }
        };
        dfs(dfs, 0);
        cout << min({dp[0][0], dp[0][1], dp[0][2]}) << '\n';
    }
    return 0;
}