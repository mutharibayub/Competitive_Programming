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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(b.rbegin(), b.rend());
        int mx = 0;
        vector<int> ans;
        for(int i = n-1; i >= 0; i--) {
            mx = max(mx, a[i]);
            while(!b.empty() && mx >= b.back()) {
                ans.push_back(b.back());
                b.pop_back();
            }
            ans.push_back(a[i]);
        }
        while(!b.empty()) {
            ans.push_back(b.back());
            b.pop_back();
        }
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < n + m; i++) {
            cout << ans[i] << " \n"[i==n+m-1];
        }
    }
    return 0;
}