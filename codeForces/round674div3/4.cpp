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

const int N = 1000+1;
const int MOD = 1e9+7;
ll fact[N];
ll factInv[N];
ll nCr(ll n, ll r)
{
    return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
}
ll pwr(ll b, ll e)
{
    ll o=1;
    while(e)
    {
        if(e&1)o=(o*b)%MOD;
        b=(b*b)%MOD;
        e/=2;
    }return o;
}
ll getInv(ll n)
{
    return pwr(n, MOD-2);
}
void initFact()
{
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%MOD;
    factInv[N-1]=getInv(fact[N-1]);
    for(int i=N-2;i>=0;i--)factInv[i]=(factInv[i+1]*(i+1))%MOD;
}

int calc(int n, int add)
{
    int baseNumber = add+1;
    int required = max(0, (n-baseNumber+baseNumber-1)/baseNumber);
    return add+required;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // initFact();

    int tttt=1;
    // cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=1;i<n;i++)arr[i]+=arr[i-1];
        set<ll> nums;
        ll dec=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!(arr[i]-dec)||nums.find(arr[i]-dec)!=nums.end())
            {
                dec+=arr[i-1]-dec;
                nums.clear();
                cnt++;
            }
            nums.insert(arr[i]-dec);
        }
        cout << cnt << '\n';
    }
    return 0;
}