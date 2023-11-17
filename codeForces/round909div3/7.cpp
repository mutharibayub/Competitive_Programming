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
        int n, q;
        cin >> n >> q;
        vector<vector<int>> al(n);
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        vector<int> locs(n), perm(n);
        for(int i = 0; i < n; i++) {
            cin >> perm[i];
            --perm[i];
            locs[perm[i]] = i;
        }
        vector<vector<pair<int, pair<int, int>>>> queries(n);
        for(int i = 0; i < q; i++) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r, --x;
            queries[x].push_back({i, {l, r}});
        } 
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);
        auto dfs = [&](auto self, int u) -> void {
            for(auto v: al[u]) {
                if(parent[u] == v) {
                    continue;
                }
                parent[v] = u;
                depth[v] = depth[u]+1;
                self(self, v);
            }
        };
        dfs(dfs, 0);
        vector<pair<int, int>> srt(n);
        for(int i = 0; i < n; i++) {
            srt[i] = {depth[i], i};
        }
        vector<int> pr(n);
        sort(srt.rbegin(), srt.rend());
        vector<set<int>> sts(n);
        for(int i = 0; i < n; i++) {
            pr[i] = i;
            sts[i].insert(locs[i]);
        }
        vector<int> ans(q, -1);
        for(int i = 0; i < n; i++) {
            int u = srt[i].second;
            int p1 = pr[u];
            for(auto [num, rng]: queries[u]) {
                auto it = sts[p1].lower_bound(rng.first);
                if(it != sts[p1].end() && *it <= rng.second) {
                    ans[num] = 1;
                } else {
                    ans[num] = 0;
                }
            }
            if(parent[u] == -1) {
                continue;
            }
            int v = parent[u];
            int p2 = pr[v];
            if(sts[p1].size() > sts[p2].size()) {
                swap(u, v);
                swap(p1, p2);
            }
            for(auto ele: sts[p1]) {
                sts[p2].insert(ele);
                pr[perm[ele]] = p2;
            }
        }
        for(int i = 0; i < q; i++) {
            cout << (ans[i]? "YES": "NO") << '\n';
        }
    }
    return 0;
}