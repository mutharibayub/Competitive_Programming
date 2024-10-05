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
        vector<int> cnt(n, 0);
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            --tmp;
            cnt[tmp]++;
        }
        int my_repeat = 0, your_repeat = 0;
        for(int i = 0; i < n; i++) {
            my_repeat += cnt[i] == 2;
            your_repeat += cnt[i] == 0;
        }
        if (your_repeat >= my_repeat) {
            cout << my_repeat << '\n';
            continue;
        }
        cout << (n - your_repeat) << '\n';
    }
    return 0;
}