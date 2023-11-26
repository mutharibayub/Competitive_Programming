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
        vector<int> in(n, 0);
        int comp_count = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<pair<int, int>> srt(n);
        for(int i = 0; i < n; i++) {
            srt[i] = {arr[i], i};
        }
        ll ans = 0;
        sort(srt.rbegin(), srt.rend());
        int cur = srt.front().first;
        for(int i = 0; i <= srt.size(); i++) {
            int my = i == srt.size()? 0: srt[i].first;
            if (cur > my) {
                ans += 1ll * comp_count * (cur - my); 
                cur = my;
            }
            comp_count++;
            if(i < srt.size()) {
                int idx = srt[i].second;
                if(idx < n - 1 && in[idx+1]) {
                    comp_count--;
                }
                if(idx && in[idx-1]) {
                    comp_count--;
                }
                in[idx] = true;
            }
        }
        cout << ans-(arr.front() > 0) << '\n';
    }
    return 0;
}