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
#include <deque>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e5+1;
ll gcd_count_pair[N];
ll gcd_count[N];
int cnt[N];

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        for(int i = 0; i < N; i++) {
            gcd_count_pair[i] = 0;
            cnt[i] = 0;
        }

        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            cnt[arr[i]]++;
        }
        sort(arr.begin(), arr.end());

        for(int i = 1; i < N; i++) {
            for(int j = i; j < N; j += i) {
                gcd_count_pair[i] += cnt[j];
            }
        }
        for(int i = 1; i < N; i++) {
            gcd_count_pair[i] = gcd_count_pair[i] * (gcd_count_pair[i]-1) / 2;
        }
        ll val = 0;
        for(int i = N - 1; i >= 1; i--) {
            if(!gcd_count_pair[i]) {
                continue;
            }
            for(int j = i + i; j < N; j += i) {
                gcd_count_pair[i] -= gcd_count_pair[j];
            }
            val += gcd_count_pair[i];
        }
        int cur = 0;
        ll ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            cur++;
            vector<int> factors;
            for(int j = 1; j*j <= arr[i]; j++) {
                if(arr[i]%j!=0) {
                    continue;
                }
                factors.push_back(j);
                if(j*j != arr[i]) {
                    factors.push_back(arr[i]/j);
                }
            }
            cnt[arr[i]]--;
            sort(factors.begin(), factors.end());
            int cc = 0;
            for(auto factor: factors) {
                cc += cnt[factor];

            }
            for(auto factor: factors) {
                
                cc -= cnt[factor];
            }
            ans += val * cur;
        }
        cout << ans << '\n';
    }
    return 0;
}