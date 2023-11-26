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
        for(auto &ele: arr) {
            cin >> ele;
        }

        bool same = true;
        for(int i = 0; i < n; i++) {
            same &= arr[i]==arr[0];
        }
        if(same) {
            cout << 0 << '\n';
            continue;
        }

        int added = 0;
        int pref = 0;
        int ans = 0;
        for(int i = 30; i > 0; i--) {
            int mn = 1e9;
            int mx = 0;
            for(int j = 0; j < n; j++) {
                mn = min(mn, arr[j]);
                mx = max(mx, arr[j]);
            }
            pref += (mx&(1<<i));
            if((mn&(1<<i)) != (mx&(1<<i))) {
                int nmn = pref - mn;
                if((1ll*nmn+mx)&(1<<i) != (mx&(1<<i))) {
                    break;
                }
                added += nmn;
                for(int j = 0; j < n; j++) {
                    arr[j] += nmn;
                }
            }
            ans = i - 1;
        }
        // cout << ans << '\n';
        cout << added << '\n';
    }
    return 0;
}