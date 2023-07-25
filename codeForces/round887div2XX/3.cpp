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

class FenwickTree
{
    vector<int> arr;
public:
    FenwickTree(int n)
    {
        arr.resize(n+1, 0);
    }
    int get(int idx)
    {
        idx++;
        int o=0;
        while(idx)
        {
            o+=arr[idx];
            idx-=idx&-idx;
        }return o;
    }
    void update(int idx, int update)
    {
        idx++;
        while(idx<arr.size())
        {
            arr[idx]+=update;
            idx+=idx&-idx;
        }
    }
};

ll check(vector<ll> &arr, ll removed, ll k)
{
    ll cnt=0;
    for(int i=0;i<k;i++)
    {
        cnt+=lower_bound(arr.begin(), arr.end(), removed-cnt+1)-arr.begin();
        if(cnt>=removed)return true;
    }return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        ll n, k;
        cin>>n>>k;
        vector<ll> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        ll removed=0;
        for(ll jmp=n*k;jmp;jmp/=2)
        {
            while(removed+jmp<=n*k&&check(arr, removed+jmp, k))removed+=jmp;    
        }
        cout << removed+1 << '\n';
    }
    return 0;
}