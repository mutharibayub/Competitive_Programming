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
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        int r = 0;
        map<int, int> counts;
        int count = 0;
        for(int l = 0; l < n; l++) {
            while (r < n && arr[r] - arr[l] < n) {
                count += counts[arr[r++]]++ == 0;
            }
            ans = max(ans, count);
            count -= (--counts[arr[l]]) == 0;
        }
        cout << ans << '\n';
    }
    return 0;
}