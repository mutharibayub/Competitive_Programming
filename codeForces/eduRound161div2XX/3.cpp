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
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> rDist(n, -1), lDist(n, -1);
        rDist.back() = lDist.front() = 0;
        for(int i = n - 2; i >= 0; i--) {
            int leftDist = !i? 1e9+7: arr[i] - arr[i-1];
            int rightDist = i==n-1? 1e9+7: arr[i+1] - arr[i];
            rDist[i] = rDist[i+1] + (rightDist > leftDist? rightDist: 1);
        }
        for(int i = 1; i < n; i++) {
            int leftDist = !i? 1e9+7: arr[i] - arr[i-1];
            int rightDist = i==n-1? 1e9+7: arr[i+1] - arr[i];
            lDist[i] = lDist[i-1] + (rightDist < leftDist? leftDist: 1);
        }
        int m;
        cin >> m;
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            int ans = 0;
            if (u < v) {
                ans = rDist[u] - rDist[v];
            } else {
                ans = lDist[u] - lDist[v];
            }
            cout << ans << '\n';
        }
    }
    return 0;
}