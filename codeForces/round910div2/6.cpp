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

const int N = 1000+1;

string grid[N];
int shortest_dists[N][N];
array<pair<int, pair<int, int>>, 2> who[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, m;
        cin >> n >> m;
        pair<int, int> start_loc = {-1, -1};
        int open_count = 0;
        for(int i = 0; i < n; i++) {
            cin >> grid[i];
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'V') {
                    start_loc = {i, j};
                } else if(grid[i][j] == '.') {
                    open_count++;
                }
                shortest_dists[i][j] = 1e9;
                who[i][j][0] = who[i][j][1] = {int(1e9), {-1, -1}};
            }
        }
        auto is_out = [&](pair<int, int> loc) {
            return loc.first == 0 || loc.first == n-1 || loc.second == 0 || loc.second == m-1 && grid[loc.first][loc.second] != '#';
        };
        auto is_valid = [&](pair<int, int> loc) {
            return loc.first >= 0 && loc.first < n && loc.second >= 0 && loc.second < m && grid[loc.first][loc.second] != '#';
        };

        auto edge_vector = vector<pair<int, int>>({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        
        queue<pair<int, int>> q;
        shortest_dists[start_loc.first][start_loc.second] = 1;
        q.push(start_loc);
        while(!q.empty()) {
            pair<int, int> top = q.front();
            int dist = shortest_dists[top.first][top.second];
            q.pop();
            for(auto [r_chg, c_chg]: edge_vector) {
                pair<int, int> new_loc = {top.first + r_chg, top.second + c_chg};
                if(is_valid(new_loc) && shortest_dists[new_loc.first][new_loc.second] == 1e9) {
                    q.push(new_loc);
                    shortest_dists[new_loc.first][new_loc.second] = dist + 1;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(shortest_dists[i][j] == 1e9 || !is_out({i, j})) {
                    continue;
                }
                q.push({i, j});
                who[i][j][0] = {1, {i, j}};
            }
        }

        auto add_shortest = [&](int i, int j, const pair<int, pair<int, int>> &to_add) {
            if(who[i][j][0].second == to_add.second || who[i][j][1].second == to_add.second) {
                return false;
            }
            if(who[i][j][1].first <= to_add.first) {
                return false;
            }
            who[i][j][1] = to_add;
            if(who[i][j][1].first < who[i][j][0].first) {
                swap(who[i][j][0], who[i][j][1]);
            }
            return true;
        };

        if(q.empty()) {
            cout << open_count << '\n';
            continue;
        } else if(q.size() == 1) {
            cout << open_count - shortest_dists[q.front().first][q.front().second] + 1 << '\n';;
            continue;
        }

        while(!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            for(auto [r_chg, c_chg]: edge_vector) {
                pair<int, int> new_loc = {top.first + r_chg, top.second + c_chg};
                if(is_valid(new_loc)) {
                    bool added = false;
                    if(who[new_loc.first][new_loc.second][1].first > who[top.first][top.second][0].first) {
                        auto to_add = who[top.first][top.second][0];
                        added |= add_shortest(new_loc.first, new_loc.second, {to_add.first + 1, to_add.second});
                    }
                    if(who[new_loc.first][new_loc.second][1].first > who[top.first][top.second][1].first) {
                        auto to_add = who[top.first][top.second][1];
                        added |= add_shortest(new_loc.first, new_loc.second, {to_add.first + 1, to_add.second});
                    }
                    if(added) {
                        q.push(new_loc);
                    }
                }
            }
        }

        int ans = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(who[i][j][1].first == 1e9) {
                    continue;
                }
                int dist = who[i][j][0].first + who[i][j][1].first - 1 + shortest_dists[i][j] - 2;
                ans = min(ans, dist);
            }
        }
        cout << open_count - ans << '\n';

    }
    return 0;
}