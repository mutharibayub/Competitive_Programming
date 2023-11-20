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
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i].first;
        }
        for(int i = 0; i < n; i++) {
            cin >> arr[i].second;
        }
        ll sm = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i].first < arr[i].second) {
                swap(arr[i].first, arr[i].second);
            }
            sm += arr[i].first - arr[i].second;
        }
        sort(arr.begin(), arr.end());
        priority_queue<pair<pair<int, int>, int>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({{arr[i].second, arr[i].first}, i});
        } 
        ll ans = 0;
        for(int i = 0; i + 1 < n; i++) {
            while(!pq.empty() && pq.top().second <= i) {
                pq.pop();
            } 
            ll minus = arr[i].first - arr[i].second + pq.top().first.second - pq.top().first.first;
            vector<int> tmp = {arr[i].first, arr[i].second};
            tmp.push_back({pq.top().first.first});
            tmp.push_back({pq.top().first.second});
            sort(tmp.rbegin(), tmp.rend());
            ll plus = tmp[0] + tmp[1] - tmp[2] - tmp[3];
            ans = max(ans, sm - minus + plus);
        }
        cout << ans << '\n';
    }
    return 0;
}