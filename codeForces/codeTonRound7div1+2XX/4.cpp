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
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        set<int> ones;
        int max_sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            max_sum += arr[i];
            if(arr[i] == 1) {
                ones.insert(i);
            }
        }
        for(int i = 0; i < q; i++) {
            int op;
            cin >> op;
            if(op == 1) {
                int first_one = ones.begin() == ones.end()? n: *ones.begin();
                int last_one = ones.rbegin() == ones.rend()? -1: *ones.rbegin();
                int twos_in_start = first_one;
                int twos_in_end = n - last_one - 1;
                int twos = min(twos_in_start, twos_in_end);
                int s;
                cin >> s;
                if(max_sum < s || ((max_sum - 1 - s) % 2 == 0 && (max_sum + 1 - s) / 2 <= twos)) {
                    cout << "NO" << '\n';
                } else {
                    cout << "YES" << '\n';
                }

            } else {
                int a, v;
                cin >> a >> v;
                --a;
                max_sum -= (ones.find(a) == ones.end()? 2: 1);
                if(v == 1) {
                    ones.insert(a);
                    max_sum += 1;
                } else {
                    ones.erase(a);
                    max_sum += 2;
                }
            }
        }
    }
    return 0;
}