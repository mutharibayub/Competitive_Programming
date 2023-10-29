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
        cin>>n;
        vector<int> arr(n);
        for(auto &ele: arr)
            cin>>ele;
        map<int, int> cnt;
        for(auto &ele: arr)
            cnt[ele]++;
        if (cnt.size() == 1 ||
            (cnt.size() == 2 && abs(cnt.begin()->second - next(cnt.begin())->second) <= 1 ))
        {
                cout << "Yes" << '\n';
                continue;
        }
        cout << "No" << '\n';
    }
    return 0;
}