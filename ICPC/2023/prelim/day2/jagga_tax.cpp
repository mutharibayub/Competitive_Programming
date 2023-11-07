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
#include <bitset>

using namespace std;

typedef long long ll;
template<typename T> using MinPQ = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e3+1;
vector<int> al[N];
int dist[N][N];
int counts[N];
bitset<N> sts[N];
vector<int> nxt[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);

    int tttt;
    cin >> tttt; 
    while (tttt--) {
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; i++) {
            al[i].clear();
            counts[i] = 0;
            for(int j = 0; j < n; j++) {
                dist[i][j] = 1e9;
            }
        }

        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        for(int i = 0; i < n; i++) {
            for(int i = 0; i < n; i++) {
                sts[i].reset();
                sts[i][i] = 1;
                nxt[i].clear();
            }
            dist[i][i] = 0;
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(auto v: al[u]) {
                    if(dist[i][v] == dist[i][u]+1) {
                        nxt[u].push_back(v);
                    } else if(dist[i][u]+1 < dist[i][v]) {
                        dist[i][v] = dist[i][u]+1;
                        nxt[u].push_back(v);
                        q.push(v);
                    }
                }
            }
            vector<pair<int, int>> tmp;
            for(int j = 0; j < n; j++) {
                tmp.push_back({dist[i][j], j});
            }
            sort(tmp.rbegin(), tmp.rend());
            for(auto [di, id]: tmp) {
                for(auto ele: nxt[id]) {
                    sts[id] |= sts[ele];
                }
            }
            for(int i = 0; i < n; i++) {
                counts[i] += sts[i].count();
            }
        }
        vector<pair<int, int>> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back({-counts[i], i});
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < min(5, n); i++) {
            cout << ans[i].second+1 << '\n';
        }
    }
    return 0;
}