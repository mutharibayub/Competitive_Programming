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
        vector<int> pts(2*n);
        int ans = 0;
        for(int i = 0; i < 2*n; i++) {
            cin >> pts[i];
        }
        sort(pts.begin(), pts.end());
        int smDiff = 0;
        for(int i = 1; i < 2*n; i++)
        {
            if(i!=n) {
                smDiff += pts[i] - pts[i-1];
            }
        }
        cout << smDiff << '\n';
        for(int i = 0; i < n; i++) {
            cout << pts[i] << ' ' << pts[i+n] << '\n';
        }
    }
    return 0;
}