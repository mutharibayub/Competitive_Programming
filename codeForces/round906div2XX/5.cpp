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
        vector<int> count(n, 0);
        vector<pair<int, int>> rngs(m);
        for(int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            --l;
            count[l]++;
            if(r < n) {
                count[r]--;
            }
            rngs[i] = {l, r-1};
        }
        for(int i = 1; i < n; i++) {
            count[i] += count[i-1];
        }
        int ans = 0;
        vector<int> low;
        for(int i = 0; i < n; i++) {
            if(count[i] == 0) {
                ans++;
            }
            else if(count[i] <= 2) {
                low.push_back(i);
            }
        }
        vector<vector<int>> cc(n);
        for(int i = 0; i < m; i++) {
            int idx = lower_bound(low.begin(), low.end(), rngs[i].first) - low.begin();
            while(idx < (int)low.size() && low[idx] <= rngs[i].second) {
                cc[low[idx]].push_back(i);
                idx++;
            }
        }
        map<pair<int, int>, int> comb_count;
        int second_max = 0;
        int max_count = 0;
        for(int i = 0; i < n; i++) {
            if((int)cc[i].size() != 1) {
                continue;
            }
            ++comb_count[{cc[i].front(), -1}];
        }
        for(auto [val, cnt]: comb_count) {
            second_max = max(second_max, cnt);
            if(second_max > max_count) {
                swap(max_count, second_max);
            }
        }
        max_count += second_max;
        for(int i = 0; i < n; i++) {
            if((int)cc[i].size() != 2) {
                continue;
            }
            pair<int, int> to_add = {cc[i].front(), cc[i].back()};
            if(to_add.first > to_add.second) {
                swap(to_add.first, to_add.second);
            }
            if(comb_count.find(to_add) == comb_count.end()) {
                comb_count[to_add] = comb_count[{to_add.first, -1}] + comb_count[{to_add.second, -1}];
            }
            max_count = max(max_count, ++comb_count[to_add]);
        }
        
        cout << ans + max_count << '\n';
    }
    return 0;
}