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
        int k, q;
        cin >> k >> q;
        vector<int> arr(k);
        for(int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        for(int i = 0; i < q; i++) {
            int n; 
            cin >> n;
            cout << min(n, arr.front() - 1) << " \n"[i==q-1];
        }
    }
    return 0;
}