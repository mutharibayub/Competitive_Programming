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

    auto conv = [&](auto self, vector<int> &arr, vector<array<int, 2>> &steps, int l, int r) -> void {
        if (l == r) {
            if (arr[l]) {
                arr[l] = 0;
                steps.push_back({l, r});
            }
            return;
        }
        self(self, arr, steps, l, r-1);
        steps.push_back({l, r-1});
        for(int i = l; i <= r-1; i++) {
            arr[i] = r - l;
        }
        self(self, arr, steps, l+1, r);
    };

    int tttt=1;
    // cin>>tttt;
    while(tttt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<vector<int>> best_sum(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            best_sum[i][i] = arr[i];
        }
        for(int ln = 1; ln <= n; ln++) {
            for(int l = 0; l + ln <= n; l++) {
                int r = l + ln - 1;
                best_sum[l][r] = max(best_sum[l][r], ln * ln);
                for(int i = l; i < r; i++) {
                    best_sum[l][r] = max(best_sum[l][r], best_sum[l][i] + best_sum[i+1][r]);
                }
            }
        }
        vector<array<int, 2>> steps;
        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j >= i; j--) {
                if (best_sum[i][j] == (j - i + 1) * (j - i + 1)) {
                    
                    conv(conv, arr, steps, i, j);
                    steps.push_back({i, j});
                    for(int ii = i; ii <= j; ii++) {
                        arr[ii] = j - i + 1;
                    }

                    i = j;
                    break;
                }
            }
        }
        cout << best_sum[0][n-1] << ' ' << steps.size() << '\n';
        for(int i = 0; i < (int)steps.size(); i++) {
            cout << steps[i][0]+1 << ' ' << steps[i][1]+1 << '\n';
        }
    }
    return 0;
}