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
        int k, n;
        cin >> n >> k;
        for(int i = 1; i < 1e9; i *= 2) {
            int count = (n + i) / (2 * i);
            if (count < k) {
                k -= count;
                continue;
            }
            cout << k * 2 * i - i << '\n';
            break;
        }
    }
    return 0;
}