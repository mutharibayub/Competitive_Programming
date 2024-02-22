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
        int n, x, y, s;
        cin >> n >> x >> y >> s;
        if (n * (x % y) % y != s % y) {
            cout << "NO" << '\n';
            continue;
        }
        ll min_sum = x % y * n;
        ll to_add = (s - min_sum) / y;
        if (to_add < 0) {
            cout << "NO" << '\n';
            continue;
        }
        vector<int> chain_lengths;
        while(to_add) {
            ll l = 1, r = to_add;
            while(l < r) {
                ll mid = (l + r + 1) / 2;
                if (mid * (mid + 1) / 2 > to_add) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            chain_lengths.push_back(l);
            to_add -= l;
        }

        int start_chain = x / y;
        if (chain_lengths.empty() && x + x%y*(n-1)==s) {
            cout << "YES" << '\n';
            for(int i = 0; i < n; i++) {
                cout << (i? x%y: x) << " \n"[i==n-1];
            }
            continue;
        }
        if (chain_lengths.empty() || start_chain > chain_lengths.front()) {
            cout << "NO" << '\n';
            continue;
        }
        chain_lengths.front() -= (x / y);
        vector<int> out = {x};
        ll sm = x;
        int next = out.back() + y;
        for(int i = 0; i < (int)chain_lengths.size(); i++) {
            for(int j = 0; j < chain_lengths[i]; j++) {
                out.push_back(next);
                sm += next;
                next += y;
            }
            if (x%y == 0 && x && i + 1 < (int)chain_lengths.size()) {
                out.push_back(0);
                next = x;
            } else {
                next = x%y;
            }
        }
        if ((int)out.size() < n && x % y == 0) {
            while ((int)out.size() < n) {
                out.push_back(0);
            }
        }
        if (out.size() != n || sm != s) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for(int i = 0; i < n; i++) {
            cout << out[i] << ' ';
        }cout << '\n';
    }
    return 0;
}