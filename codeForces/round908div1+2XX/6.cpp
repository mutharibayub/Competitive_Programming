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
        int n, m;
        cin >> n >> m;
        vector<int> cubes(n, 0);
        vector<vector<int>> shelves_filled(m);
        vector<vector<vector<int>>> shelves_groups(m);
        vector<pair<int, int>> shelves_meta(m);
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            --tmp;
            cubes[tmp]++;
        }
        for(int i = 0; i < m; i++) {
            cin >> shelves_meta[i].first;
        }
        priority_queue<pair<int, pair<int, int>>> pq;
        for(int i = 0; i < m; i++) {
            cin >> shelves_meta[i].second;
            shelves_groups[i].resize((shelves_meta[i].first + shelves_meta[i].second - 1) / shelves_meta[i].second);
            shelves_filled[i].resize(shelves_meta[i].first, -1);
            for(int j = 0; j < shelves_meta[i].first; j += shelves_meta[i].second) {
                pq.push({min(shelves_meta[i].first, j + shelves_meta[i].second) - j, {i, j / shelves_meta[i].second}});
            }
        }
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(!cubes[i]) {
                continue;
            }
            vector<pair<int, pair<int, int>>> stk;
            if((int)pq.size() < cubes[i]) {
                ok = false;
                break;
            }
            for(int j = 0; j < cubes[i]; j++) {
                auto [count, group_info] = pq.top();
                pq.pop();
                if(count - 1) {
                    stk.push_back({count - 1, group_info});
                } 
                shelves_groups[group_info.first][group_info.second].push_back(i);
            }
            while (!stk.empty()) {
                pq.push(stk.back());
                stk.pop_back();
            }
        }
        if(!ok) {
            cout << -1 << '\n';
            continue;
        }
        for(int i = 0; i < m; i++) {
            for(int j = shelves_groups[i].size() - 1; j >= 0; j--) {
                int start_idx = j * shelves_meta[i].second;
                int end_idx = min(shelves_meta[i].first - 1, start_idx + shelves_meta[i].second - 1);
                int last_end_idx = min(shelves_meta[i].first - 1, end_idx + 1 + shelves_meta[i].second - 1);
                set<int> to_put;
                for(auto &ele: shelves_groups[i][j]) {
                    to_put.insert(ele);
                }
                for(int k = last_end_idx; k > end_idx; k--) {
                    assert(shelves_filled[i][k] != -1);
                    if(to_put.find(shelves_filled[i][k]) != to_put.end()) {
                        shelves_filled[i][k - shelves_meta[i].second] = shelves_filled[i][k];
                        to_put.erase(shelves_filled[i][k]);
                    }
                }
                auto it = to_put.begin();
                for(int k = start_idx; k <= end_idx; k++) {
                    if(shelves_filled[i][k] == -1) {
                        assert(it != to_put.end());
                        shelves_filled[i][k] = *it;
                        it++;
                    }
                }
                assert(it == to_put.end());
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < shelves_filled[i].size(); j++) {
                cout << shelves_filled[i][j] + 1 << " \n"[j==shelves_filled[i].size() - 1];
            }
        }
    }
    return 0;
}