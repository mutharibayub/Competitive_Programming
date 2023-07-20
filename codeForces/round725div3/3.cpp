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

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

const int MOD = 1e9+7;

ll pwr(ll n, ll e)
{
    ll o=1;
    while(e)
    {
        if(e%2)o=o*n%MOD;
        e/=2;
        n=n*n%MOD;
    }return o;
}

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, lll, rr;
        cin>>n>>lll>>rr;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.begin(), arr.end());
        ll cnt=0;
        for(int i=0;i<n;i++)
        {
            int mn=lower_bound(arr.begin(), arr.end(), lll-arr[i])-arr.begin();
            int mx=lower_bound(arr.begin(), arr.end(), rr-arr[i]+1)-arr.begin()-1;
            mn=max(mn, i+1);
            if(mn<=mx)cnt+=mx-mn+1;
        }
        cout << cnt << '\n';
    }    

    return 0;
}