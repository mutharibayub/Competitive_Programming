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
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int, int> cnts;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            if (cnts.find(INT_MAX ^ arr[i]) != cnts.end()) {
                if(!--cnts[INT_MAX ^ arr[i]]) {
                    cnts.erase(INT_MAX ^ arr[i]);
                }
                count += 1;
                continue;
            }
            cnts[arr[i]]++;
        }
        for(auto [_, cnt]: cnts) {
            count += cnt;
        }
        cout << count << '\n';
    }
    return 0;
}