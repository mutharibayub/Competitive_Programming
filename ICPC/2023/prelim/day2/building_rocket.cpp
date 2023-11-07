#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <queue>
#include <functional>
#include <limits>
#include <numeric>
#include <string>

using namespace std;

typedef long long ll;
template<typename T> using MinPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string tt;
    getline(cin, tt);
    int tttt = stoi(tt);
    // int tttt = 1;
    // cin >> tttt; 
    // cin.ignore();
    while (tttt--) {
        string s = "";
        getline(cin, s);
        while(s.back() == ' ')
            s.pop_back();
        string tmp = "";
        vector<ll> arr;
        for(int i = 0; i <= s.size(); i++) {
            if(i == s.size() || s[i]==' ') {
                if(tmp == "") {
                    continue;
                }
                arr.push_back(stoll(tmp));
                tmp = "";
                continue;
            } 
            tmp.push_back(s[i]);
        }
        int n = arr.size();
        if (n == 0) {
            cout << 0 << '\n';
            continue;
        }
        vector<vector<ll>> cost(n, vector<ll>(n, 1e18));
        for(int i = 0; i < n; i++) {
            cost[i][i] = 0;
        }
        for(int i = 2; i <= n; i++) {
            for(int l = 0; l+i-1 < n; l++) {
                int r = l+i-1;
                for(int cut = l; cut < r; cut++) {
                    cost[l][r] = min(cost[l][r], cost[l][cut]+cost[cut+1][r]+arr[l]+arr[r]);
                }
            }
        }
        cout << cost[0][n-1] << '\n';
    }
    return 0;
}