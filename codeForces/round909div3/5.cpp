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
        for(auto &ele: arr) {
            cin >> ele;
        }
        int sorted_till = n-1;
        while(sorted_till && arr[sorted_till] >= arr[sorted_till-1]) {
            sorted_till--;
        }
        bool ok = true;
        for(int i = 0; i < sorted_till && ok; i++) {
            ok &= (arr[i] > arr[sorted_till]);
        }
        cout << (ok? sorted_till: -1) << '\n';
    }
    return 0;
}