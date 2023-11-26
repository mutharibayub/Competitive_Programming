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
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for(auto &ele: arr) {
            cin >> ele;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int cur = arr[i];
            int prev = i? arr[i-1]: 0;
            ans = max(ans, cur - prev);
        }
        ans = max(ans, 2*(x - arr.back()));
        cout << ans << '\n';
    }
    return 0;
}