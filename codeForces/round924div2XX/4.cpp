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

ll calc_ans(vector<int> &cre, int b, int x, int grps) {
    ll out = 0;
    for(int i = 0; i < (int)cre.size(); i++) {
        out += 1ll * b * cre[i] * (cre[i] - 1) / 2;
        int val = cre[i]/grps;
        int higher = cre[i]%grps;
        int lower = grps - higher;
        out -= 1ll * b * val * (val - 1) / 2 * lower;
        out -= 1ll * b * val * (val + 1) / 2 * higher;
    }
    return out - 1ll * (grps - 1) * x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, b, x;
        cin >> n >> b >> x;
        vector<int> cre(n);
        for(auto &ele: cre) {
            cin >> ele;
        }
        ll ans = 0;
        int l = 1, r = 2e5;
        ll lans = calc_ans(cre, b, x, l), rans = calc_ans(cre, b, x, r);
        while (l < r) {
            if (r - l == 0) {
                ans = lans;
                r--;
            } else if (r - l == 1) {
                ans = max(lans, rans);
                r-=2;
            } else if (r - l == 2) {
                ans = max({lans, rans, calc_ans(cre, b, x, r-1)});
                r = l - 1;
            } else {
                int diff = (r - l) / 3;
                int mid1 = l + diff, mid2 = l + 2 * diff;
                ll mid1ans = calc_ans(cre, b, x, mid1), mid2ans = calc_ans(cre, b, x, mid2);
                if (mid1ans < mid2ans) {
                    l = mid1;
                    lans = mid1ans;
                } else {
                    r = mid2;
                    rans = mid2ans;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}