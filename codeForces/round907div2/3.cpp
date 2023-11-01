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
        vector<long long> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());

        int l = 0, r = n-1;
        int x = 0;
        long long ans = 0;
        while(l <= r)
        {
            if(l == r)
            {
                ans += min((arr[l] - x + 3) / 2, arr[l]);
                break;
            }
            int req = arr[r] - x;
            assert(req >= 0);
            int hits = arr[l];
            int goingToHit = min(req, hits);
            ans += goingToHit;
            arr[l] -= goingToHit;
            x += goingToHit;
            req = arr[r] - x;
            if(arr[l] == 0)
                l++;
            if(req == 0)
            {
                ans++;
                x = 0;
                r--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}