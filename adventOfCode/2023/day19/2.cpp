#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <string>
#include <set>

using namespace std;

typedef long long ll;

vector<string> split(const string &s, char delim) {
    vector<string> out;
    string tmp = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == delim) {
            out.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp.push_back(s[i]);
    }
    out.push_back(tmp);
    return out;
}

int main() {

    freopen("input.txt", "r", stdin);

    map<char, int> chr_map;
    chr_map['x'] = 0;
    chr_map['m'] = 1;
    chr_map['a'] = 2;
    chr_map['s'] = 3;

    map<string, vector<pair<array<int, 3>, string>>> al;
    string s = "";
    while(true) {
        cin >> s;
        if(s[0] == '{') {
            break;
        }
        vector<string> tmp;
        tmp = split(s, '{');
        string in = tmp[0];
        tmp = split(tmp[1].substr(0, tmp[1].size() - 1), ',');
        for(auto rule: tmp) {
            if(rule.find(':') == -1) {
                al[in].push_back(make_pair(array<int, 3>({-1, -1, -1}), rule));
                continue;
            }
            auto _ = split(rule, ':');
            string cond = _[0];
            array<int, 3> parsed_cond;
            if (cond.find('>') != -1) {
                parsed_cond[1] = 0;
                auto tt = split(cond, '>');
                parsed_cond[0] = chr_map[tt[0][0]];
                parsed_cond[2] = stoi(tt[1]);
            } else {
                parsed_cond[1] = 1;
                auto tt = split(cond, '<');
                parsed_cond[0] = chr_map[tt[0][0]];
                parsed_cond[2] = stoi(tt[1]);
            }
            al[in].push_back(make_pair(parsed_cond, _[1]));
        }
    }

    ll ans = 0;
    auto dfs = [&](auto self, array<pair<int, int>, 4> cur, string node) -> void {
        if (node == "R") {
            return;
        }
        if(node == "A") {
            ll val = 1;
            for(auto [start, end]: cur) {
                val *= end - start + 1;
            }
            ans += val;
            return;
        }
        for (auto [cond, child]: al[node]) {
            if (cond[0] == -1) {
                self(self, cur, child);
                continue;
            }
            if (cond[1] == 0) { // '>' cond
                auto tmp = cur;
                tmp[cond[0]].first = max(tmp[cond[0]].first, cond[2]+1);
                cur[cond[0]].second = min(cur[cond[0]].second, cond[2]);
                if(tmp[cond[0]].first<=tmp[cond[0]].second) {
                    self(self, tmp, child);
                }
                if(cur[cond[0]].first>cur[cond[0]].second) {
                    return;
                }
            } else { // '<' cond
                auto tmp = cur;
                tmp[cond[0]].second = min(tmp[cond[0]].second, cond[2]-1);
                cur[cond[0]].first = max(cur[cond[0]].first, cond[2]);
                if(tmp[cond[0]].first<=tmp[cond[0]].second) {
                    self(self, tmp, child);
                }
                if(cur[cond[0]].first>cur[cond[0]].second) {
                    return;
                }
            }
        }
    };

    array<pair<int, int>, 4> start = {};
    for(auto &ele: start) {
        ele = {1, 4000};
    }
    dfs(dfs, start, "in");
    cout << ans << '\n';

    return 0;
}