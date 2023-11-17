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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<bool> done(n, 0);
        int ptr = n-1;
        bool ok = true;
        for(int i = 0; i < k && ok; i++) {
            if(arr[ptr] > n) {
                ok = false;
                break;
            } else if(done[ptr]) {
                break;
            }
            done[ptr] = true;
            ptr = (ptr - arr[ptr] + n) % n;
        }
        cout << (ok? "Yes": "No") << '\n';
    }
    return 0;
}