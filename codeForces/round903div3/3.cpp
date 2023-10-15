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
        cin>>n;
        vector<string> grid(n);
        for(int i=0;i<n;i++)
        {
            cin>>grid[i];
        }
        int ans = 0;
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                vector<int> vals = {grid[i][j], grid[n-j-1][i], grid[n-i-1][n-j-1], grid[j][n-i-1]};
                int mx = 0;
                for(int i=0; i<4; i++)
                    mx = max(mx, vals[i]);
                for(int i=0; i<4; i++)
                    ans += (mx-vals[i]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}