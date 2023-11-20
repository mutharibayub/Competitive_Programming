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
        int n, m, k;
        cin >> n >> m >> k;
        if(k - n - m + 2 < 0 || (k - n - m + 2)%2) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m - 1; j++) {
                if(i < n - 2) {
                    cout << 'R';
                } else {
                    cout << ((n+j)%2? 'R': 'B');
                }
                cout << ' ';
            }
            cout << '\n';
        }
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < m; j++) {
                if(!j) {
                    cout << (i%2? 'B': 'R');
                } else if(j == 1) {
                    cout << 'B';
                } else {
                    cout << ((n+m)%2? 'B': 'R');
                }
                cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}