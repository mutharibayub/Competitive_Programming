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
        vector<ll> count(n+1, 0), with_gcd(n+1, 0), factors(n+1, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            count[arr[i]]++;
        }
        for(int i = 1; i < n+1; i++)
        {
            ll cnt = 0;
            for(int j = i; j < n+1; j+=i)
            {
                factors[j] += count[i];
                cnt += count[j];
            }
            with_gcd[i] = 1ll * cnt * (cnt-1) / 2;
        }
        for(int i = n; i > 0; i--)
        {
            for(int j = 2*i; j < n+1; j+=i)
            {
                with_gcd[i] -= with_gcd[j];
            }
        }
        ll ans = 1ll * n * (n-1) / 2;
        for(int i = 1; i < n+1; i++)
        {
            if(with_gcd[i] && factors[i] > 0)
            {
                ans -= with_gcd[i];
            }
        }
        cout << ans << '\n';
    }   
    return 0;
}