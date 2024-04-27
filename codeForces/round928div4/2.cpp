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
        int n;
        cin >> n;
        vector<string> grid(n);
        for(int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        int one_count = 0;
        int mnx, mny, mxx, mxy;
        mnx = mny = 1e9;
        mxx = mxy = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                one_count += grid[i][j] == '1';
                if (grid[i][j] == '1') {
                    mnx = min(mnx, i);
                    mny = min(mny, j);
                    mxx = max(mxx, i);
                    mxy = max(mxy, j);
                }
            }
        }
        cout << ((mxy-mny+1)*(mxx-mnx+1) == one_count? "SQUARE": "TRIANGLE") << '\n';
    }
    return 0;
}