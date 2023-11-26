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
        int n, x;
        cin >> n >> x;
        vector<pair<int, int>> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool ok = true;
        vector<int> assignment(n, -1);
        for(int i = n - 1; i >=0 && ok; i--) {
            if(n - i <= x) {
                assignment[a[i].second] = b[x - 1 - (n - 1 - i)].first;
                if(a[i].first <= b[x - 1 - (n - 1 - i)].first) {
                    ok = false;
                }
            } else {
                assignment[a[i].second] = b.back().first;
                if(a[i].first > b.back().first) {
                    ok = false;
                }
                b.pop_back();
            }
        }
        if(!ok) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for(int i = 0; i < n; i++) {
            cout << assignment[i] << " \n"[i==n-1];
        }
    }
    return 0;
}