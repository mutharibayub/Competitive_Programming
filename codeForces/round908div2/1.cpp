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
        int win_count[] = {0, 0};
        for(int x = 1; x <= n; x++) {
            int cnt[2] = {0, 0};
            int a_cnt = 0, b_cnt = 0;
            for(int j = 0; j < n; j++) {
                a_cnt += s[j]=='A';
                b_cnt += s[j]=='B';
                if(a_cnt == x || b_cnt == x) {
                    cnt[b_cnt==x]++;
                    a_cnt = b_cnt = 0;
                }
            }
            if(!a_cnt && !b_cnt && (cnt[0] || cnt[1]) && 'A'+(cnt[1] > cnt[0]) == s.back()) {
                win_count[cnt[1] > cnt[0]]++;
            }
        }
        if(win_count[0] ^ win_count[1]) {
            cout << (win_count[0]? 'A': 'B') << '\n';
            continue;
        }
        cout << '?' << '\n';
    }
    return 0;
}