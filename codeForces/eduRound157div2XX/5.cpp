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
        int n;
        cin >> n;
        vector<pair<int, int>> mc(n);
        for(int i = 0; i < n; i++) {
            cin >> mc[i].first;
        }
        for(int i = 0; i < n; i++) {
            cin >> mc[i].second;
        }
        int m;
        cin >> m;
        vector<pair<int, int>> bc(m);
        for(int i = 0; i < m; i++) {
            cin >> bc[i].first;
        }
        for(int i = 0; i < m; i++) {
            cin >> bc[i].second;
        }
        sort(mc.begin(), mc.end());
        sort(bc.begin(), bc.end());
        vector<pair<int, int>> m_def(n), b_def(m);
        for(int i = 0; i < n; i++) {
            m_def[i] = {mc[i].second, i};
        }
        for(int i = 0; i < m; i++) {
            b_def[i] = {bc[i].second, i};
        }
        for(int i = n-2; i >= 0; i--) {
            m_def[i] = max(m_def[i], m_def[i+1]);
        }
        for(int i = m-2; i >= 0; i--) {
            b_def[i] = max(b_def[i], b_def[i+1]);
        }
        vector<int> m_dp(n, -1), b_dp(m, -1);
        vector<int> m_in(n, 0), b_in(m, 0);
        auto calc = [&](auto self, int p, int i) -> int {
            if (p) {
                if (b_dp[i] == -1) {
                    if(b_in[i]) {
                        b_dp[i] = 2; // draw
                    } else if (bc[i].second >= mc.back().first) {
                        b_dp[i] = 1; // win
                    } else {
                        b_in[i] = true;
                        int counter_idx = lower_bound(mc.begin(), mc.end(), make_pair(bc[i].second+1, 0)) - mc.begin();
                        int counter = m_def[counter_idx].second;
                        int val = self(self, !p, counter);
                        b_dp[i] = (val == 2? 2: !val);
                        b_in[i] = false;
                    }
                }
                return b_dp[i];
            } else {
                if (m_dp[i] == -1) {
                    if(m_in[i]) {
                        m_dp[i] = 2; // draw
                    } else if (mc[i].second >= bc.back().first) {
                        m_dp[i] = 1; // win
                    } else {
                        m_in[i] = true;
                        int counter_idx = lower_bound(bc.begin(), bc.end(), make_pair(mc[i].second+1, 0)) - bc.begin();
                        int counter = b_def[counter_idx].second;
                        int val = self(self, !p, counter);
                        m_dp[i] = (val == 2? 2: !val);
                        m_in[i] = false;
                    }
                }
                return m_dp[i];
            }
        };
        int count[3] = {0};
        for(int i = 0; i < n; i++) {
            count[calc(calc, 0, i)]++;
        }
        swap(count[0], count[1]);
        swap(count[1], count[2]);
        for(int i = 0; i < 3; i++) {
            cout << count[i] << " \n"[i==2];
        }
    }
    return 0;
}