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

using namespace std;

typedef long long ll;
template<typename T> using MinPQ = priority_queue<T, vector<T>, greater<T>>;

ll ccount(int n, vector<vector<int>> &departments, int idx, vector<int> &done) {
    ll cc = 0;
    if(idx == n-1) {
        for(int i = 0; i < departments[idx].size(); i++) {
            cc += !done[departments[idx][i]];
        }
    } else {
        for(int i = 0; i < departments[idx].size(); i++) {
            if(!done[departments[idx][i]]) {
                done[departments[idx][i]] = true;
                cc += ccount(n, departments, idx+1, done);
                done[departments[idx][i]] = false;
            }
        }
    }
    return cc;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt;
    cin >> tttt; 
    while (tttt--) {
        int n;
        cin >> n;
        vector<vector<int>> departments(n);
        for(int i = 0; i < n; i++) {
            int c;
            cin >> c;
            for(int j = 0; j < c; j++) {
                int tmp;
                cin >> tmp;
                departments[i].push_back(tmp);
            }
        }
        vector<int> done(100+1, 0);
        cout << ccount(n, departments, 0, done) << '\n';
    }
    return 0;
}