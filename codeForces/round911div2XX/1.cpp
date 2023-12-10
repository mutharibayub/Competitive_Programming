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
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i]=='#') {
                continue;
            }
            int j = i;
            while(j < n && s[j] == '.') {
                j++;
            }
            if(j - i > 2) {
                cnt = 2;
                break;
            }
            cnt += j - i;
            i = j;
        }
        cout << cnt << '\n';
    }
    return 0;
}