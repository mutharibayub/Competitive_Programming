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
        vector<vector<int>> al(n);
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += al[i].size() == 1;
        }

        cout << (cnt+1)/2 << '\n';
    }
    return 0;
}