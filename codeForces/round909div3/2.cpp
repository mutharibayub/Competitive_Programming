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
        vector<ll> pref;
        for(auto &ele: arr) {
            cin >> ele;
            pref.push_back((pref.empty()? 0: pref.back()) + ele);
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            if(n%i) {
                continue;
            }
            ll maxSum = 0;
            ll minSum = 1e18;
            for(int j = 0; j+i-1 < n; j+=i) {
                int start = j, end = j+i-1;
                ll sum = pref[end] - (start? pref[start-1]: 0);
                maxSum = max(maxSum, sum);
                minSum = min(minSum, sum);
            }
            ans = max(ans, maxSum - minSum);
        }
        cout << ans << '\n';
    }
    return 0;
}