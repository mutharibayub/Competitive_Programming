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
const int MOD = 998244353;
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

int getParent(vector<int> &parent, int u)
{
    if(parent[parent[u]]!=parent[u])
    {
        parent[u]=getParent(parent, parent[u]);
    }return parent[u];
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
        vector<ll> mx1(n+1, -1e18), mx2(n+1, -1e18), mx3(n+1, -1e18), mx4(n+1, -1e18);
        vector<int> a(n, 0), b(n, 0);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
        dp[0][0]=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=min(i, k);j++)
            {
                int unused=i-j;
                if(i)
                {
                    dp[i][j]=max(dp[i][j], dp[i-1][j]);
                    dp[i][j]=max(dp[i][j], mx1[unused]+a[i-1]+b[i-1]);
                    dp[i][j]=max(dp[i][j], mx2[unused]-a[i-1]-b[i-1]);
                    dp[i][j]=max(dp[i][j], mx3[unused]-a[i-1]+b[i-1]);
                    dp[i][j]=max(dp[i][j], mx4[unused]+a[i-1]-b[i-1]);
                }
                if(i<n)
                {
                    mx1[unused]=max(mx1[unused], dp[i][j]-a[i]-b[i]);
                    mx2[unused]=max(mx2[unused], dp[i][j]+a[i]+b[i]);
                    mx3[unused]=max(mx3[unused], dp[i][j]-a[i]+b[i]);
                    mx4[unused]=max(mx4[unused], dp[i][j]+a[i]-b[i]);
                }
            }
        }
        cout << dp[n][k] << '\n';
    }
    return 0;
}