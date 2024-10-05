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
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &ele: arr) {
            cin >> ele;
        }

        while(1) {
            int first_consec = 0, max_consec = 0, curr_consec = 0;
            for(int i = 0; i < n; i++) {
                if(arr[i] == 0) {
                    curr_consec = 0;
                } else {
                    curr_consec++;
                }
                max_consec = max(max_consec, curr_consec);
                if (curr_consec == i+1) {
                    first_consec = curr_consec;
                }
            }
            if (curr_consec < n) {
                max_consec = max(max_consec, curr_consec + first_consec);
            }
            if (max_consec <= 3 - (n <= 3) - (n <= 2)) {
                break;
            }
            for(int i = 0; i < n; i++) {
                arr[(i+1)%n] = max(0, arr[(i+1)%n] - arr[i]);
            }
        }
        int zero_loc = 0;
        for(int i = 0; i < n; i++) {
            if (!arr[i]) {
                zero_loc = i;
                break;
            }
        }
        vector<int> surv;
        vector<int> curr;
        for(int i = 0; i <= n; i++) {
            int idx = (zero_loc + i) % n;
            if (!arr[idx]) {
                assert(curr.size() <= 3);
                if (curr.empty()) {
                    continue;
                }
                surv.push_back(curr.front());
                if (curr.size() == 3) {
                    if (curr[0] < curr[1]) {
                        arr[curr[1]] -= arr[curr[0]];
                    }
                    int fix_val = (arr[curr[0]] - arr[curr[1]] % arr[curr[0]]) % arr[curr[0]];
                    int rounds = (arr[curr[1]] + fix_val) / arr[curr[0]];
                    ll total_dmg = 1ll * rounds * (rounds + 1) / 2 * arr[curr[0]] - 1ll * fix_val * rounds;
                    if (arr[curr[2]] > total_dmg) {
                        surv.push_back(curr[2]);
                    }
                }
                curr.clear();
                continue;
            }
            curr.push_back(idx);
        }
        sort(surv.begin(), surv.end());
        cout << surv.size() << '\n';
        for(int i = 0; i < surv.size(); i++) {
            cout << surv[i] + 1 << " \n"[i == surv.size()-1];
        }

    }
    return 0;
}