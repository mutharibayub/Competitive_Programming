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

class FenwickTree {
    vector<int> arr;
public:
    FenwickTree(int n) {
        arr.resize(n+1, 0);
    }
    int get(int i) {
        i++;
        int o = 0;
        while(i) {
            o += arr[i];
            i -= i&-i;
        }
        return o;
    }
    void update(int i, int x) {
        i++;
        while(i < arr.size()) {
            arr[i] += x;
            i += i&-i;
        }
    }
};

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
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]--;
        }
        FenwickTree fwt(2*n);
        vector<pair<int, int>> meta(n);
        for(int i = 0; i < n; i++) {
            int go_to = arr[i];
            if(go_to < i) {
                go_to += n;
            }
            meta[i] = {go_to, arr[i]};
            fwt.update(go_to, +1);
            if(go_to + n < 2*n) {
                fwt.update(go_to+n, +1);
            }
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            fwt.update(meta[i].first, -1);
            int sum = fwt.get(meta[i].first);
            int length = meta[i].first - i;
            ans[meta[i].second] = length - sum;
        }
        for(int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i==n-1];
        }
    }
    return 0;
}