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
    cin>>tttt;
    while(tttt--) {
        string s;
        cin >> s;
        set<string> keywords;
        int max_len = 0;
        string tmp = "";
        for(int i = 0; i <= s.size(); i++) {
            if(i == s.size() || s[i] == ',') {
                keywords.insert(tmp);
                max_len = max(max_len, (int)tmp.size());
                tmp = "";
                continue;
            }
            tmp.push_back(s[i]);
        }
        string to_make;
        cin >> to_make;
        vector<ll> dp(to_make.size()+1, 0);
        dp.front() = 1;
        for(int i = 0; i < to_make.size(); i++) {
            if(dp[i] == 0) {
                continue;
            }
            tmp = "";
            for(int j = 0; j < max_len && i+j < to_make.size(); j++) {
                tmp.push_back(to_make[i+j]);
                if(keywords.find(tmp) != keywords.end()) {
                    dp[i+j+1] += dp[i];
                }
            }
        }
        cout << dp.back() << '\n';
    }
    return 0;
}