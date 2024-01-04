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
    // cin>>tttt;
    while(tttt--)
    {
        int m;
        cin >> m;
        int cnts[31] = {0};
        for(int i = 0; i < m; i++) {
            int t, v;
            cin >> t >> v;
            if(t==1) {
                cnts[v]++;
                continue;
            }
            int tmp[31];
            for(int i = 0; i < 31; i++) {
                tmp[i] = cnts[i];
            }
            bool ok = true;
            for(int i = 30; i >= 0 && ok; i--) {
                int need = (v>>i)&1;
                for(int j = i; j >= 0 && need; j--) {
                    int use = min(need, tmp[j]);
                    need -= use;
                    tmp[j] -= use;
                    need <<= 1;
                }
                if(need) {
                    ok = false;
                }
            }
            cout << (ok? "YES": "NO") << '\n';
        }

    }
    return 0;
}