#include <iostream>
#include <vector>

using namespace std;

int const max_value = (1 << 13);
vector < int > g[max_value];
int ans[max_value], r[max_value];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    ans[0] = 1;
    for (int i = 0; i < max_value; ++i) {
        g[i].push_back(0);
    }
    for (int i = 0; i < max_value; ++i) {
        r[i] = max_value;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (auto key : g[x]) {
            int to = (key^x);
            ans[to] = 1;
            while (r[to] > x) {
                r[to]--;
                if (r[to] != x) g[r[to]].push_back(to);
            }
        }
        g[x] = {};
    }

    for(int i=0;i<20;i++)
    {
        cout<<ans[i]<<' ';
    }cout<<'\n';

    int k = 0;
    for (int i = 0; i < max_value; ++i) {
        k += ans[i];
    }
    cout << k << '\n';
    for (int i = 0; i < max_value; ++i) {
        if (ans[i]) cout << i << " ";
    }
    cout << '\n';
    return 0;
}