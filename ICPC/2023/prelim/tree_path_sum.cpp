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
 
bool valid_int(const string &s) {
    if(s == "") {
        return false;
    }
    for(int i = 0; i < s.size(); i++) {
        if(s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

vector<int> read_line() {
    string s;
    getline(cin, s);
    while(s.back() == ' ')
        s.pop_back();
    vector<int> out;
    string tmp = "";
    for(int i = 0; i <= s.size(); i++) {
        if(i==s.size() || s[i] == ' ') {
            if(!valid_int(tmp)) {
                tmp = "";
                continue;
            }
            out.push_back(stoi(tmp));
            tmp = "";
            continue;
        }
        tmp.push_back(s[i]);
    }
    return out;
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int tttt=1;
    cin>>tttt;
    cin.ignore();
    while(tttt--) {
        vector<int> in_order, post_order, queries;
        in_order = read_line();
        post_order = read_line();
        queries = read_line();
        vector<int> found(queries.size(), 0);
        map<int, int> to_check;
        for(int i = 0; i < queries.size(); i++) {
            to_check[queries[i]] = i;
        }
        map<int, int> locs;
        for(int i = 0; i < in_order.size(); i++) {
            locs[in_order[i]] = i;
        }
        int root = post_order.back();
        map<int, vector<int>> children;
        map<int, int> parent;
        map<int, vector<int>> al;
        map<int, int> depth;
        auto build = [&](auto self, int l, int r, int p, int &i) -> void {
            if(l>r) {
                return;
            }
            int nxt = post_order[i];
            parent[nxt] = p;
            if(p != -1) {
                al[nxt].push_back(p);
                al[p].push_back(nxt);
                children[p].push_back(nxt);
            }
            int split = locs[nxt];
            assert(split >= l && split <=r);
            i--;
            self(self, split+1, r, nxt, i);
            self(self, l, split-1, nxt, i);
        };
        set<int> in_arm;
        auto dfs = [&](auto self, int u, int len) -> void {
            if(to_check.find(len) != to_check.end()) {
                found[to_check[len]] = 1;
                to_check.erase(len);
            }
            in_arm.insert(u);
            for(auto v: al[u]) {
                if(in_arm.find(v) != in_arm.end()) {
                    continue;
                }
                self(self, v, len+v);
            }
            in_arm.erase(u);
        };
        int idx = post_order.size() - 1;
        build(build, 0, (int)in_order.size() - 1, -1, idx);
        for(int i = 0; i < in_order.size(); i++) {
            dfs(dfs, in_order[i], in_order[i]);
        }
        for(int i = 0; i < found.size(); i++) {
            cout << (found[i]? "TRUE": "FALSE") << '\n'; 
        }
    }
    return 0;
}