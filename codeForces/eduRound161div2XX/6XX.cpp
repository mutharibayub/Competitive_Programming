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
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (auto &ele: arr) {
            cin >> ele;
            --ele;
        }

        // check for case 0: all numbers are same
        bool same = true;
        for (int i = 0; i < n && same; i++) {
            same &= (arr[i] == arr[0]);
        }
        if (same) {
            cout << 0 << '\n';
            continue;
        }

        // check for case 1: a certain number does not exist
        vector<int> exists(x, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += (exists[arr[i]]++) == 0;
        }
        if (count < x) {
            cout << 1 << '\n';
            continue;
        }

        int ans = 1e9;

        // special case of case 2: convert islands without a certain number to that number
        for (int k = 0; k < x; k++) {
            count = 0;
            int last = k;
            for (int i = 0; i < n; i++) {
                if (last == k && arr[i] != k) {
                    count++;
                }
                last = arr[i];
            }
            ans = min(ans, count);
        }

        // case 2: convert array to case 1
        vector<vector<vector<int>>> inv_dp(n, vector<vector<int>>(n, vector<int>(x, 1e9)));
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(x, 1e9)));
        vector<vector<int>> done(n, vector<int>(n, 0));

        //   cover trivial segments
        for (int i = 0; i < n; i++) {
            exists.assign(x, 0);
            count = 0;
            for (int j = i; j < n; j++) {
                count += (exists[arr[j]]++) == 0;
                if (count == x) {
                    break;
                }
                done[i][j] = 1;
                for (int k = 0; k < x; k++) {
                    if (exists[k]) {
                        inv_dp[i][j][k] = 1;
                    } else {
                        inv_dp[i][j][k] = 0;
                    }
                }
            }
        }

        //    cover non trivial segments
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                // continue if sub-segment does not have all the distinct numbers
                if (done[l][r]) {
                    continue;
                }

                vector<vector<int>> inds(x);

                for (int i = l; i <= r; i++) {
                    inds[arr[i]].push_back(i);
                }

                int min_value = 1e9;
                for (int k = 0; k < x; k++) {
                    if (arr[l] == k || arr[r] == k) {
                        for (int cut = 0; cut < inds[k].size() - 1; cut ++) {
                            inv_dp[l][r][k] = min(inv_dp[l][r][k], inv_dp[inds[k].front()][inds[k][cut]][k] + inv_dp[inds[k][cut+1]][inds[k].back()][k]);
                        }
                    } else {
                        inv_dp[l][r][k] = min(inv_dp[l][r][k], inv_dp[inds[k].front()][inds[k].back()][k]);
                    }
                    min_value = min(min_value, inv_dp[l][r][k]);
                }
                for (int k = 0; k < x; k++) {
                    inv_dp[l][r][k] = min(inv_dp[l][r][k], min_value + 1);
                }
            }
        }
        for(int k = 0; k < x; k++) {
            ans = min(ans, inv_dp[0][n-1][k] + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}