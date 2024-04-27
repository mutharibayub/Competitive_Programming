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

    auto get_sum = [](int num) -> int {
        int sm = 0;
        while(num) {
            sm += num%10;
            num /= 10;
        }
        return sm;
    };

    vector<ll> arr((int)2e5+1);
    for(int i = 1; i <= 2e5; i++) {
        arr[i] = get_sum(i);
        if (i > 1) {
            arr[i] += arr[i - 1];
        }
    }

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin >> n;
        cout << arr[n] << '\n';
    }
    return 0;
}