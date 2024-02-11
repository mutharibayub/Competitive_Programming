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
        map<int, int> cnts;
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            cnts[tmp]++;
        }
        ll ans = 0;
        int done_count = 0;
        for(auto [num, cnt]: cnts) {
            ans += 1ll * cnt * (cnt - 1) * (cnt - 2) / 6;
            ans += 1ll * cnt * (cnt - 1) * done_count / 2;
            done_count += cnt;
        }
        cout << ans << '\n';
    }
    return 0;
}