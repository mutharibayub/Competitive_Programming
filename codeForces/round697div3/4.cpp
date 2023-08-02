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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, m;
        cin>>n>>m;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        vector<ll> ones, twos;
        for(int i=0;i<n;i++)
        {
            if(b[i]==1)ones.push_back(a[i]);
            else twos.push_back(a[i]);
        }
        sort(ones.rbegin(), ones.rend());
        sort(twos.rbegin(), twos.rend());
        for(int i=1;i<ones.size();i++)ones[i]+=ones[i-1];
        for(int i=1;i<twos.size();i++)twos[i]+=twos[i-1];
        ll best = 1e9+7;
        for(int i=0;i<=(int)ones.size();i++)
        {
            ll done=(i?ones[i-1]:0);
            if(done>=m)
            {
                best=min(best, 1ll*i);
                break;
            }
            ll req=max(0ll, m-done);
            if(twos.empty()||req>twos.back())continue;
            int toAdd = lower_bound(twos.begin(), twos.end(), req)-twos.begin()+1;
            best=min(best, i+2ll*toAdd);
        }
        cout << (best==1e9+7?-1:best) << '\n';
    }
    return 0;
}