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
        vector<int> arr(n);
        for(auto &ele: arr) {
            cin >> ele;
        }
        int larger = arr.back();
        ll ans = 0;
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] <= larger) {
                larger = arr[i];
                continue;
            }
            int req = (arr[i] + larger - 1) / larger;
            ans += req - 1;
            larger = arr[i] / req;
        }
        cout << ans << '\n';
    }
    return 0;
}