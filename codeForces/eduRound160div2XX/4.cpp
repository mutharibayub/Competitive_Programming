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

const int MOD = 998244353;

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
        vector<int> llwr(n);
        vector<int> stk;
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && arr[stk.back()] > arr[i]) {
                stk.pop_back();
            }
            llwr[i] = (stk.empty()? -1: stk.back());
            stk.push_back(i);
        }
        vector<ll> dp(n);
        vector<ll> pref(n);
        vector<ll> chain_sum(n);
        dp.front() = pref.front() = chain_sum.front() = 1;
        for(int i = 1; i < n; i++) {
            dp[i] = (llwr[i]==-1? 0: chain_sum[llwr[i]]) + pref[i-1] - (llwr[i]==-1? -1: pref[llwr[i]]);
            dp[i] = (dp[i]%MOD+MOD)%MOD;
            chain_sum[i] = dp[i] + (llwr[i] == -1? 0: chain_sum[llwr[i]]);
            chain_sum[i] %= MOD;
            pref[i] = (pref[i-1] + dp[i])%MOD;
        }
        int mn = 1e9+7;
        ll ans = 0;
        for(int i = n-1; i >= 0; i--) {
            if(mn > arr[i]) {
                mn = arr[i];
                ans = (ans + dp[i])%MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}