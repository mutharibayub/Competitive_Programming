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
        ll m, c;
        cin >> m >> c;
        map<ll, int> costs;
        costs[0]++;
        for(int i = 0; i < c; i++) {
            int cnt;
            cin >> cnt;
            map<ll, int> tCosts = costs;
            for(int j = 0; j < cnt; j++) {
                ll cost;
                cin >> cost;
                for(auto [c, cc]: tCosts) {
                    costs[c+cost] += cc;
                }
            }
            for(auto [c, cc]: tCosts) {
                costs[c] -= cc;
                int now_count = costs[c];
                assert(now_count >= 0);
                if(!costs[c]) {
                    costs.erase(c);
                }
            }
        }
        auto it = costs.lower_bound(m+1);
        if (it == costs.begin()) {
            cout << -1 << '\n';
            continue;
        }
        cout << (prev(it)->first) << '\n';
    
    }
    return 0;
}