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
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        bool ok = true;
        for(int i = 1; i <= n && ok; i*=2)
        {
            for(int j = 0; i+j+1 < n && j + 1 < i && ok; j++)
            {
                ok &= (arr[i+j] <= arr[i+j+1]);
            }
        }
        cout << (ok? "YES": "NO") << '\n';
    }
    return 0;
}