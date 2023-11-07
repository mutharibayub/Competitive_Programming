#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <queue>
#include <functional>
#include <limits>
#include <numeric>

using namespace std;

typedef long long ll;
template<typename T> using MinPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt;
    cin >> tttt; 
    while (tttt--) {
        int n;
        cin >> n;
        vector<vector<int>> al(n);
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        vector<int> in_path(n, 0);
        pair<int, int> max_dist = {-1, -1};
        auto dfs = [&](auto self, int u, int dist) -> void {
            in_path[u] = true;
            if (dist > max_dist.first) {
                max_dist = {dist, u};
            }
            for(auto v: al[u]) {
                if(in_path[v]) {
                    continue;
                }
                self(self, v, dist+1);
            }
            in_path[u] = false;
        };
        dfs(dfs, 0, 0);
        int start = max_dist.second;
        max_dist = {-1, -1};
        dfs(dfs, start, 0);
        cout << (max_dist.first%2? 2: 1) << '\n';
    }
    return 0;
}