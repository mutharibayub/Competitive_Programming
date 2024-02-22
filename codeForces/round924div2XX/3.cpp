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
        int n, x;
        cin >> n >> x;
        set<int> ks;
        for(auto cand: vector<int>({n+x-2, n-x})) {
            if (cand <= 0) {
                continue;
            }
            for(int y = 1; cand/y >= y; y++) {
                if (cand % y == 0) {
                    if (y % 2 == 0 && y/2+1 >= x) {
                        ks.insert(y/2+1);
                    }
                    if (cand / y != y) {
                        if (cand / y % 2 == 0 && cand/y/2+1 >= x) {
                            ks.insert(cand/y/2+1);
                        }
                    }
                }
            }
        }
        cout << (int)ks.size() << '\n';
    }
    return 0;
}