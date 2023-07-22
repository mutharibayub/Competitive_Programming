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

#define int ll

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<int> arr(n+2);
        for(int i=0;i<n+2;i++)cin>>arr[i];
        sort(arr.begin(), arr.end());
        int found=-1;
        int esm=arr.back();
        int sm=0;
        for(int i=0;i<n+1;i++)sm+=arr[i];
        for(int i=0;i<n+1&&found==-1;i++)
        {
            if(sm-arr[i]==esm)found=i;
        }
        if(found!=-1)
        {
            for(int i=0;i<n+1;i++)
            {
                if(i==found)continue;
                cout << arr[i] << ' '; 
            }cout << '\n';
            continue;
        }
        sm-=arr[n];
        if(sm==arr[n])
        {
            for(int i=0;i<n;i++)
            {
                if(i)cout << ' ';
                cout << arr[i];
            }cout << '\n';
            continue;
        }
        cout << -1 << '\n';
    }
    return 0;
}