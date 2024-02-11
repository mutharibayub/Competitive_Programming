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
        string a, b, c;
        cin >> a >> b >> c;
        bool ok = false;
        for(int i = 0; i < n && !ok; i++) {
            ok |= (a[i] != c[i]) && (b[i] != c[i]);
        }
        cout << (ok? "YES": "NO") << '\n';
    }
    return 0;
}