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
        vector<int> arr(n);
        map<int, int> cnt;
        for(auto &ele: arr) {
            cin >> ele;
            cnt[ele]++;
        }
        ll ans = 0;
        for(auto [num, count]: cnt) {
            ans += 1ll * count * (count - 1) / 2;
        }
        ans += 1ll * cnt[1] * cnt[2];
        cout << ans << '\n';
    }
    return 0;
}