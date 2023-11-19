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
        ll n, c;
        cin >> n >> c;
        vector<ll> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        priority_queue<pair<ll, int>> pq;
        for(int i = 1; i < n; i++) {
            pq.push({arr[i]-(i+1)*c, i});
        }
        ll sum = arr.front();
        bool ok = true;
        while(!pq.empty()) {
            if(pq.top().first + sum < 0) {
                ok = false;
                break;
            }
            sum += arr[pq.top().second];
            pq.pop();
        }
        cout << (ok? "Yes": "No") << '\n';
    }
    return 0;
}