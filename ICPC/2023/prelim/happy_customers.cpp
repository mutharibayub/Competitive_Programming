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

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int tttt=1;
    // cin>>tttt;
    while(tttt--) {
        int n, d;
        cin >> n >> d;
        int a_size, b_size;
        cin >> a_size >> b_size;
        vector<pair<int, int>> req;
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            req.push_back({a*a_size+b*b_size, i});
        }
        sort(req.begin(), req.end());
        int sm = 0;
        vector<int> ans;
        for(int i = 0; i < req.size(); i++) {
            if(sm + req[i].first > d) {
                break;
            }
            sm += req[i].first;
            ans.push_back(req[i].second);
        }
        cout << (int) ans.size() << '\n';
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] + 1 << " \n"[i==ans.size()-1];
        }
    }
    return 0;
}