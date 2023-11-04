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
        int x, y, k;
        cin >> x >> y >> k;
        if(x < y) {
            x = min(x+k, y);
            cout << y + (y-x) << '\n';
            continue;
        }
        cout << x << '\n';
    }
    return 0;
}