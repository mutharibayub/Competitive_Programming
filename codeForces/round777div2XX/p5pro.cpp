#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
 
const int K = 30;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> cnt(n);
    vector<vector<int>> up(n, vector<int> (K));
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        ++cnt[a];
        up[i][0] = a;
    }
    // cout<<"__\n";
    for (int k = 1; k < K; ++k) {
        for (int i = 0; i < n; ++i) {
            up[i][k] = up[up[i][k - 1]][k - 1];
            // cout<<up[i][k]+1<<" ";
        }
        // cout<<"\n";
    }
    // cout<<"__\n";
    vector<int> a(n);
    int cnt_bad = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!cnt[i]) {
            ++cnt_bad;
        }
    }
    int k = (*max_element(a.begin(), a.end()) - n) / cnt_bad;
    vector<vector<int>> add(n);
 
    for (int i = 0; i < n; ++i) {
        int v = i, level = k;
        for (int j = K - 1; j >= 0; --j) {
            if (level >= (1 << j)) {
                level -= (1 << j);
                v = up[v][j];
            }
        }
        cout<<v+1<<" ";
        add[a[v] - 1].push_back(i);
    }cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<": ";
        for(auto it:add[i])
        {
            cout<<it+1<<" ";
        }cout<<"\n";
    }

    set<int> now;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (add[i].size()) {
            int res = *min_element(add[i].begin(), add[i].end());
            for (int j : add[i]) {
                if (j != res) {
                    now.emplace(j);
                }
            }
            ans[res] = i + 1;
        } else {
            ans[*now.begin()] = i + 1;
            now.erase(*now.begin());
        }
    }
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}