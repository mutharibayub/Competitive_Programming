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

vector<vector<int>> al;

vector<int> read_line() {
    string s;
    getline(cin, s);
    while(s.back() == ' ')
        s.pop_back();
    string tmp = "";
    vector<int> arr;
    for(int i = 0; i <= s.size(); i++) {
        if(i == s.size() || s[i]==' ') {
            if(tmp == "") {
                continue;
            }
            assert(tmp.size() == 1);
            arr.push_back(tmp.front() - 'A');
            tmp = "";
            continue;
        } 
        tmp.push_back(s[i]);
    }
    return arr;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a = read_line(), b = read_line();

    vector<vector<int>> can_make(26);
    vector<vector<int>> al(26);
    for(int i = 0; i < a.size(); i++) {
        al[a[i]].push_back(b[i]);
    }
    for(int i = 0; i < 26; i++) {
        queue<int> q;
        q.push(i);
        vector<bool> done(26, 0);
        can_make[i].push_back(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto v: al[u]) {
                if(!done[v]) {
                    done[v] = true;
                    q.push(v);
                    can_make[i].push_back(v);
                }
            }
        }   
    }

    string line = "";
    while (getline(cin, line))
    {
        int space_at = line.find(' ');
        string first = line.substr(0, space_at);
        string second = line.substr(space_at+1);
        bool ok = (first.size() >= 3 && first.size() <= 20);
        for(int i = 0; i < first.size() && ok; i++) {
            int start = first[i]-'A';
            int end = second[i]-'A';
            bool found = false;
            for(int j = 0; j < can_make[start].size(); j++) {
                if (can_make[start][j] == end) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                ok = false;
            }
        }
        cout << (ok? "Yes": "No") << endl;
    }

    return 0;
}