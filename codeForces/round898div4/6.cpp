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

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

// const int N = 1e5+1;
// const int MOD = 998244353;
// // ll fact[N];
// // ll factInv[N];
// // ll nCr(ll n, ll r)
// // {
// //     return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
// // }
// // ll pwr(ll b, ll e)
// // {
// //     ll o=1;
// //     while(e)
// //     {
// //         if(e&1)o=(o*b)%MOD;
// //         b=(b*b)%MOD;
// //         e/=2;
// //     }return o;
// // }
// // ll getInv(ll n)
// // {
// //     return pwr(n, MOD-2);
// // }
// // void initFact()
// // {
// //     fact[0]=1;
// //     for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%MOD;
// //     factInv[N-1]=getInv(fact[N-1]);
// //     for(int i=N-2;i>=0;i--)factInv[i]=(factInv[i+1]*(i+1))%MOD;
// // }

int getParent(vector<int> &parent, int u)
{
    if(parent[parent[u]]!=parent[u])
    {
        parent[u]=getParent(parent, parent[u]);
    }return parent[u];
}

int getMx(vector<int> &arr, int k)
{
    vector<ll> pref(arr.size());
    pref.front() = arr.front();
    for(int i=1;i<arr.size();i++)
        pref[i]=pref[i-1]+arr[i];

    int ans = 0;

    for(int i=0;i<arr.size();i++)
    {
        int l = i;
        int r = arr.size()-1;
        while(l<r)
        {
            int mid = (l+r+1)/2;
            ll sm = pref[mid] - (i?pref[i-1]:0);
            if (sm <= k)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if(pref[l]-(i?pref[i-1]:0) <= k)
            ans = max(ans, l-i+1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // initFact();

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, k;
        cin>>n>>k;

        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<int> h(n);
        for(int i=0;i<n;i++)
            cin>>h[i];

        int ans = 0;
        vector<int> arr;
        vector<int> heights;
        for(int i=0;i<n;i++)
        {
            if(heights.empty() || heights.back()%h[i]==0)
            {
                heights.push_back(h[i]);
                arr.push_back(a[i]);
            }
            else
            {
                ans=max(ans, getMx(arr, k));
                arr = {a[i]};
                heights = {h[i]};
            }
        }
        if(!arr.empty())ans = max(ans, getMx(arr, k));
        cout << ans << '\n';
    }
    return 0;
}