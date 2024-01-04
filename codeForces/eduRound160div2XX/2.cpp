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

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        string s;
        cin >> s;
        int one_count = 0, zero_count = 0;
        for(int i = 0; i < s.size(); i++) {
            one_count += (s[i]=='1');
            zero_count += (s[i]=='0');
        }
        int req_one = zero_count, req_zero = one_count;
        int ans = 0;
        for(int i = s.size() - 1; i >= 0; i--, ans++) {
            if(req_one == one_count && req_zero == zero_count) {
                break;
            }
            req_one -= (s[i] == '0');
            req_zero -= (s[i] == '1');
            if(req_one < one_count) {
                one_count--;
            } else {
                zero_count--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}