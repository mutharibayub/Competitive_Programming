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
        int n = 7;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        int final_ans = 0;
        for (int type = 0; type < 2; type++){
            vector<ll> dp(n*n, 0); 
            for (int i = 1; i < n - 1; i++) {
                for(int j = 1; j < n - 1; j++) {
                    if ((i+j)%2 == type) {
                        continue;
                    }
                    vector<vector<int>> coords = {{i, j}, {i+1, j+1}, {i+1, j-1}, {i-1, j+1}, {i-1, j-1}};
                    bool all_good = true;
                    for (auto coord: coords) {
                        all_good &= grid[coord[0]][coord[1]] == 'B';
                    }
                    if (!all_good) {
                        continue;
                    }
                    for(auto coord: coords) {
                        dp[coord[0]*n+coord[1]] |= (1ll << (i*n+j));
                    }
                }
            }
            ll all_union = 0;
            for(auto ele: dp) {
                all_union |= ele;
            }
            for(int i = 0; i < dp.size(); i++) {
                for(int j = 0; j < dp.size(); j++) {
                    if (i == j) {
                        continue;
                    }
                    if ((dp[i]|dp[j]) == dp[i]) {
                        dp[j] = 0;
                    }
                }
            }
            sort(dp.rbegin(), dp.rend());
            int ans = 1e9;
            auto search = [&](auto self, int idx, ll cur, int count) -> void {
                if (cur == all_union) {
                    ans = min(ans, count);
                    return;
                }
                if (idx == dp.size() || dp[idx] == 0) {
                    return;
                }
                if (cur | dp[idx] != cur) {
                    self(self, idx + 1, cur | dp[idx], count + 1);
                }
                self(self, idx + 1, cur, count);
            };
            search(search, 0, 0, 0);
            final_ans += ans;
        }
        cout << final_ans << '\n';
    }
    return 0;
}