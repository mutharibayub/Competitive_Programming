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
    // cin>>tttt;
    while(tttt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &ele: arr) {
            cin >> ele;
        }
        vector<int> ans = arr;
        int mx = -1e9;
        for(int i = 0; i < n; i++) {
            ans[i] = max(ans[i], mx + n - i - 1);
            mx = max(mx + 1, arr[i] + 1);
        }
        mx = 0;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] = max(ans[i], mx + i);
            mx = max(mx + 1, arr[i] + 1);
        }
        int final_ans = 2e9;
        for(int i = 0; i < n; i++) {
            final_ans = min(final_ans, ans[i]);
        }
        cout << final_ans << '\n';
    }
    return 0;
}