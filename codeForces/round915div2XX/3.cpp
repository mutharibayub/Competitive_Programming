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
        string s;
        cin >> s;
        vector<int> idx;
        for(int i = n - 1; i >= 0; i--) {
            if(idx.empty() || s[i] >= s[idx.back()]) {
                idx.push_back(i);
            }
        }
        int max_char = s[idx.back()];
        int max_count = 0;
        string tmp = "";
        for(int i = 0; i < (int)idx.size(); i++) {
            if(s[idx[i]] == max_char) {
                max_count++;
            } else {
                tmp.push_back(s[idx[i]]);
            }
        }
        reverse(idx.begin(), idx.end());
        for(int i = 0; i < (int)idx.size(); i++) {
            if(i < tmp.size()) {
                s[idx[i]] = tmp[i];
            } else {
                s[idx[i]] = max_char;
            }
        }
        // cout << s << '\n';
        bool is_sorted = true;
        for(int i = 1; i < n && is_sorted; i++) {
            is_sorted &= (s[i] >= s[i-1]);
        }
        cout << (is_sorted? (int)idx.size() - max_count: -1) << '\n';
    }
    return 0;
}