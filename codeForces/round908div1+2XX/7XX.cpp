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

using Mat = array<array<ll, 3>, 3>;

const int MOD = 998244353;

Mat mult(const Mat &left, const Mat &right) {
    Mat out;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            out[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                out[i][j] += left[i][k] * right[k][j] % MOD;
            }
            out[i][j] %= MOD;
        }
    }
    return out;
}

Mat pwr(Mat n, ll e) {
    Mat init;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            init[i][j] = (i==j);
        }
    }
    while(e) {
        if(e&1) {
            init = mult(init, n);
        }
        e >>= 1;
        n = mult(n, n);
    }
    return init;
}

ll pwr(ll n, ll e) {
    ll init = 1;
    while(e) {
        if(e&1) {
            init = (init*n)%MOD;
        }
        e >>= 1;
        n = (n*n)%MOD;
    }
    return init;
}

ll getInv(ll n) {
    return pwr(n, MOD-2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    // cin>>tttt;
    for(int ttt = 1; ttt <= tttt; ttt++)
    {
        int n, m; 
        cin >> n >> m;
        vector<vector<pair<int, int>>> al(m);
        for(int i = 0; i < m; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            --u, --v;
            al[u].push_back({v, d});
            al[v].push_back({u, d});
        }
        vector<int> in_cycle(n, -1);
        vector<vector<int>> cycles;
        vector<int> in_arm(n, 0);
        vector<pair<int, ll>> arm;
        auto cycle_dfs = [&](auto self, int u, int p) -> void {
            in_arm[u] = true;
            arm.push_back({u, 0});
            for(auto [v, d]: al[u]) {
                if(v == p) {
                    continue;
                }
                arm.back().second = 2*d-1;
                if(in_arm[v]) {
                    cycles.push_back({});
                    for(auto ele: arm) {
                        cycles.back().push_back(ele);
                        in_cycle[ele] = (int)cycles.size() - 1;
                    }
                } else {
                    self(self, v, u);
                }
            }
            arm.pop_back();
            in_arm[u] = false;
        };
        cycle_dfs(cycle_dfs, 0, -1);
        for(int i = 0; i < n; i++) {
            if(in_cycle[i] == -1) {
                cycles.push_back({i});
                in_cycle[i] = (int)cycles.size() - 1;
            }
        }
        vector<vector<int>> tree_al((int)cycles.size());
        for(int i = 0; i < n; i++) {
            for(auto [v, d]: al[i]) {
                if(in_cycle[i] != in_cycle[v]) {
                    tree_al[in_cycle[i]].push_back(in_cycle[v]);
                }
            }
        }
        vector<pair<int, int>> parent((int)cycles.size(), -1);
        vector<int> depth((int)cycles.size(), 0);
        auto tree_dfs = [&](auto self, int u) -> void {
            for(auto v: tree_al[u]) {
                if(parent[u] == v) {
                    continue;
                }
                parent[v] = u;
                depth[v] = depth[v] + 1;
                self(self, v);
            }
        };
        tree_dfs(tree_dfs, 0);
        vector<pair<int, int>> srt((int)cycles.size());
        for(int i = 0; i < (int)cycles.size(); i++) {
            srt[i] = {depth[i], i};
        }
        sort(srt.rbegin(), srt.rend());
        
    }
    return 0;
}