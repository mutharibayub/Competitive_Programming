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
        string s, t;
        cin >> s >> t;
        vector<vector<int>> locs(26);
        for(int i = n - 1; i >= 0; i--) {
            locs[s[i]-'a'].push_back(i);
        }
        bool ok = true;
        for(int i = 0; i < m; i++) {
            if(locs[t[i]-'a'].empty()) {
                ok = false;
                break;
            }
            int cur = locs[t[i]-'a'].back();
            locs[t[i]-'a'].pop_back();
            for(int j = t[i]-'a'-1; j >= 0; j--) {
                while(!locs[j].empty() && locs[j].back() < cur) {
                    locs[j].pop_back();
                }
            }
        }
        cout << (ok? "YES": "NO") << '\n';
    }
    return 0;
}