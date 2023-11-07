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
        vector<int> arr(n);
        vector<int> cnt(100+1, 0);
        int ccnt = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            ccnt += ++cnt[arr[i]] == 2;
        }
        if(ccnt < 2) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> b(n, 1);
        vector<int> mults;
        for(int i = 0; i < 100+1; i++) {
            if(cnt[i] >= 2) {
                mults.push_back(i);
            }
        }
        for(int i = 0; i < n; i++) {
            if(arr[i] == mults[0] && cnt[arr[i]] > 1) {
                b[i] = 2;
                cnt[arr[i]]--;
            }
            if(arr[i] == mults[1] && cnt[arr[i]] > 1) {
                b[i] = 3;
                cnt[arr[i]]--;
            }
        }
        for(int i = 0; i < n; i++) {
            cout << b[i] << " \n"[i==n-1];
        }
    }
    return 0;
}