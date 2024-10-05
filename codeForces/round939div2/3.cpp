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
        int sum = n * n * n;
        for(int i = n - 1; i >= 1; i--) {
            sum -= i * i;
        }
        cout << sum << ' ' << 2 * n << '\n';
        for(int i = 0; i < n; i++) {
            cout << 1 << ' ' << n - i << ' ';
            for(int j = 0; j < n; j++) {
                cout << j + 1 << " \n"[j==n-1];
            }
            cout << 2 << ' ' << n - i << ' ';
            for(int j = 0; j < n; j++) {
                cout << j + 1 << " \n"[j==n-1];
            }
        }
    }
    return 0;
}