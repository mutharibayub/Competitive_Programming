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
        int n;
        cin>>n;
        vector<array<int,2>> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i][0],arr[i][1]=i;
        sort(arr.begin(), arr.end());
        int add=0;
        int l=0, r=n-1, cur=n;
        bool ok=true;
        vector<int> ans(n);
        while(l<=r)
        {
            if(arr[l][0]+add<0)
            {
                ok=false;
                break;
            }
            while(l<=r&&arr[l][0]+add==0)ans[arr[l][1]]=-cur,l++,cur--;
            if(l>r)break;
            if(arr[r][0]+add!=cur)
            {
                ok=false;
                break;
            }
            ans[arr[r][1]]=cur;
            cur--,add--,r--;
        }
        if(!ok)
        {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << ans[i];
        }cout << '\n';
    }
    return 0;
}