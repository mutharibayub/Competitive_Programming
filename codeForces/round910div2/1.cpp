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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += s[i] == 'B';
        }
        int needed = k - cnt;
        if(needed == 0) {
            cout << 0 << '\n';
            continue;
        }  
        int changed = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(needed < 0) {
                changed += s[i]=='B';
            } else {
                changed -= s[i]=='A';
            }
            if(changed + needed == 0) {
                ans = i;
                break;
            }
        }
        cout << 1 << '\n';
        cout << (ans + 1) << ' ' << (needed < 0? 'A': 'B') << '\n';
    }
    return 0;
}