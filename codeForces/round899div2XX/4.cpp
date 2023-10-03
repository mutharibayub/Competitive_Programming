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

// const int N = 2e5+1;
// const int MOD = 998244353;
// ll fact[N];
// ll factInv[N];
// ll nCr(ll n, ll r)
// {
//     return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
// }
// ll pwr(ll b, ll e)
// {
//     ll o=1;
//     while(e)
//     {
//         if(e&1)o=(o*b)%MOD;
//         b=(b*b)%MOD;
//         e/=2;
//     }return o;
// }
// ll getInv(ll n)
// {
//     return pwr(n, MOD-2);
// }
// void initFact()
// {
//     fact[0]=1;
//     for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%MOD;
//     factInv[N-1]=getInv(fact[N-1]);
//     for(int i=N-2;i>=0;i--)factInv[i]=(factInv[i+1]*(i+1))%MOD;
// }

int getParent(vector<int> &parent, int u)
{
    if(parent[parent[u]]!=parent[u])
    {
        parent[u]=getParent(parent, parent[u]);
    }return parent[u];
}

const int MAXN = 2e5+1;
vector<int> al[MAXN];
int parent[MAXN];
int sz[MAXN];
int a[MAXN];
ll sum0[MAXN];
ll sum1[MAXN];
ll ans[MAXN];
int bit;
int n;

void dfs(int u)
{ 
    sz[u]=1;
    ll tsum0=0, tsum1=0;
    for(int v: al[u])
    {
        if(parent[u]==v)
            continue;
        parent[v]=u;
        dfs(v);
        sz[u]+=sz[v];
        tsum0+=sum0[v];
        tsum1+=sum1[v];
    }
    sum0[u]=(((a[u]>>bit)&1)!=0)?sz[u]*(1ll<<bit)+tsum1:tsum0;
    sum1[u]=(((a[u]>>bit)&1)!=1)?sz[u]*(1ll<<bit)+tsum0:tsum1;
}

void dfs1(int u, ll upSum0, ll upSum1)
{
    ll tsum0=0, tsum1=0;
    for(int v: al[u])
    {
        if(parent[u]==v)
            continue;
        tsum0 += sum0[v];
        tsum1 += sum1[v];
    }
    if(parent[u]!=-1)
    {
        tsum0+=upSum0;
        tsum1+=upSum1;
    }
    ll s0=(((a[u]>>bit)&1)!=0)?n*(1ll<<bit)+tsum1:tsum0;
    ll s1=(((a[u]>>bit)&1)!=1)?n*(1ll<<bit)+tsum0:tsum1;
    ans[u] += min(s0, s1);
    for(int v: al[u])
    {
        if(parent[u]==v)
            continue;
        tsum0 -= sum0[v];
        tsum1 -= sum1[v];

        s0=(((a[u]>>bit)&1)!=0)?(n-sz[v])*(1ll<<bit)+tsum1:tsum0;
        s1=(((a[u]>>bit)&1)!=1)?(n-sz[v])*(1ll<<bit)+tsum0:tsum1;
        dfs1(v, s0, s1);

        tsum0 += sum0[v];
        tsum1 += sum1[v];
    }
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
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        for(int i=0;i<n;i++)
        {
            ans[i]=0;
            parent[i]=-1;
            al[i].clear();
        }
        for(int i=0;i<n-1;i++)
        {
            int u, v;
            cin>>u>>v;
            u--, v--;
            al[u].push_back(v);
            al[v].push_back(u);
        }

        for(int i=0;i<20;i++)
        {
            bit=i;
            for(int j=0;j<n;j++)
            {
                sum0[j]=0;
                sum1[j]=0;
            }
            dfs(0);
            dfs1(0, 0, 0);
        }
        for(int i=0;i<n;i++)
            cout << ans[i] << " \n"[i==n-1];
    }
    return 0;
}