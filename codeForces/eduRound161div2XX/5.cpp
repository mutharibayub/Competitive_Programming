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
        ll x;
        cin >> x;
        --x;
        vector<ll> sums;
        vector<int> smaller, bigger;
        int cur_biggest = -1;

        while(x > 0 && (int)sums.size() <= 200) {
            int smallerThan = -1;
            ll biggestSum = 0;
            ll all_sum = 0;
            for(int i = sums.size() - 1; i >= 0; i--) {
                if(sums[i] <= x - 1 && sums[i] > biggestSum) {
                    biggestSum = sums[i];
                    smallerThan = i;
                }
            }
            x -= biggestSum + 1;
            sums.push_back(2ll*biggestSum+1);
            bigger.push_back(smallerThan);
            smaller.push_back(-1);
            if (smallerThan == -1) {
                if (cur_biggest != -1) {
                    bigger[cur_biggest] = sums.size() - 1;
                    smaller[sums.size() - 1] = cur_biggest;
                }
                cur_biggest = sums.size() - 1;
            } else {
                smaller[sums.size() - 1] = smaller[smallerThan];
                if (smaller[bigger[sums.size() - 1]] != -1) {
                    bigger[smaller[smallerThan]] = sums.size() - 1;
                }
                smaller[bigger[sums.size() - 1]] = sums.size() - 1;
            }
        }
        
        if ((int)sums.size() > 200) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> ans(sums.size());
        int i = sums.size();
        while(cur_biggest != -1) {
            ans[cur_biggest] = i;
            cur_biggest = smaller[cur_biggest];
            i--;
        }
        reverse(ans.begin(), ans.end());
        cout << (int)ans.size() << '\n';
        for(int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i] << " \n"[i == (int)ans.size() - 1];
        }
    }
    return 0;
}