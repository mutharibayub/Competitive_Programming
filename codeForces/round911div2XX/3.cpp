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
#include <deque>

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
        string s;
        cin >> s;
        vector<int> parent(n, -1);
        vector<pair<int, int>> children(n);
        vector<vector<pair<int, int>>> al(n);
        vector<int> is_leaf(n, 1);
        for(int i = 0; i < n; i++) {
            int lc, rc;
            cin >> lc >> rc;
            children[i] = {lc - 1, rc - 1};
            if(lc) {
                parent[lc - 1] = i;
            }
            if(rc) {
                parent[rc - 1] = i;
            }
            is_leaf[i] = !lc && !rc;
        }
        for(int i = 0; i < n; i++) {
            if(parent[i] != -1) {
                al[i].push_back({parent[i], s[i]!='U'});
            }
            if(children[i].first != -1) {
                al[i].push_back({children[i].first, s[i]!='L'});
            }
            if(children[i].second != -1) {
                al[i].push_back({children[i].second, s[i]!='R'});
            }
        }
        deque<pair<int, int>> q;
        vector<int> dist(n, 1e9);
        q.push_back({0, 0});
        int ans = 1e9;
        while(!q.empty()) {
            auto [u, d] = q.front();
            q.pop_front();
            dist[u] = d;
            if(is_leaf[u]) {
                ans = dist[u];
                break;
            }
            for(auto [v, w]: al[u]) {
                if(w) {
                    q.push_back({v, d + 1});
                } else {
                    q.push_front({v, d});
                }
            }
            while(!q.empty() && dist[q.front().first] < 1e9) {
                q.pop_front();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}