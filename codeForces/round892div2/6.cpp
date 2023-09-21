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

const int N = 1e5+1;
const int MOD = 998244353;
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

int up[N][21];
int depth[N];
int upDist[N];
ll s1Dist[N][21];
ll s2Dist[N][21];

void dfs(vector<vector<pair<int, int>>> &al, int u)
{
    for(auto &[v, w]: al[u])
    {
        if(up[u][0]==v)continue;
        up[v][0]=u;
        upDist[v]=w;
        depth[v]=depth[u]+1;
        dfs(al, v);
    }
}

int LCA(int u, int v)
{
    if(depth[u]>depth[v])swap(u, v);
    for(int i=20;depth[v]>depth[u]&&i>=0;i--)
    {
        if(depth[v]-(1<<i) >= depth[u])
        {
            v = up[v][i];
        }
    }
    for(int i=20;u!=v&&i>=0;i--)
    {
        if(up[u][i]!=up[v][i])
        {
            v = up[v][i];
            u = up[u][i];
        }
    }
    if(u!=v)
    {
        v = up[v][0];
        u = up[u][0];
    }return u;
}

ll getDist(int u, int lca, bool dist1=true)
{
    ll dist = 1e12;
    for(int i=20;i>=0&&u>=0;i--)
    {
        if(depth[u]-(1<<i)<depth[lca]-1)continue;
        dist = min(dist, dist1?s1Dist[u][i]:s2Dist[u][i]);
        u = up[u][i];
    }
    return dist;
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
        int n, T;
        cin>>n>>T;
        
        for(int i=0;i<n;i++)
        {
            depth[i]=0;
            upDist[i]=0;
            for(int j=0;j<21;j++)
            {
                up[i][j]=-1;
                s1Dist[i][j]=1e12;
                s2Dist[i][j]=1e12;
            }
        }
        
        vector<vector<pair<int, int>>> al(n);
        for(int i=0;i<n-1;i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            u--,v--;
            al[u].push_back({v, w});
            al[v].push_back({u, w});
        }

        string s;
        cin>>s;
        
        dfs(al, 0);
        
        int qqqq;
        cin>>qqqq;
        vector<pair<int, int>> queries(qqqq);
        vector<ll> ans(qqqq, 1e12);
        for(auto &query: queries)
        {
            cin>>query.first>>query.second;
            query.first--,query.second--;
        }

        vector<pair<int, int>> srt(n);
        for(int i=0;i<n;i++)srt[i]={depth[i], i};
        sort(srt.rbegin(), srt.rend());
        
        for(int i=1;i<21;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(up[j][i-1]!=-1)
                    up[j][i]=up[up[j][i-1]][i-1];
            }
        }

        vector<ll> dd(n), h1(n), h2(n);
        int div=2;

        for(int iter=1;iter<21;iter++, div*=2)
        {
            minPQ<pair<ll, int>> pq; 
            for(int i=0;i<n;i++)
            {
                dd[i]=1e12;
                if(s[i]=='1')
                    pq.push({0, i});
            }
            while(!pq.empty())
            {
                auto [dist, top] = pq.top();
                pq.pop();
                dd[top]=dist;
                for(auto [v, w]:al[top])
                {
                    if(dd[v]!=1e12)continue;
                    pq.push({dist+w+(w+div-1)/div, v});
                }
                while(!pq.empty() && dd[pq.top().second]!=1e12)pq.pop();
            }

            h1[srt[n-1].second]=h2[srt[n-1].second]=0;
            for(int i=n-1;i>=0;i--)
            {
                int u = srt[i].second;
                if(i<n-1)
                {
                    h1[u]=h1[up[u][0]]+upDist[u];
                    h2[u]=h2[up[u][0]]+(upDist[u]+div-1)/div;
                }
                s1Dist[u][0] = -h1[u]+dd[u]+h2[u];
                s2Dist[u][0] = h1[u]+dd[u]-h2[u];
            }

            for(int i=1;i<21;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(depth[j]-(1<<i) < -1)continue;
                    s1Dist[j][i]=min(s1Dist[j][i-1], s1Dist[up[j][i-1]][i-1]);
                    s2Dist[j][i]=min(s2Dist[j][i-1], s2Dist[up[j][i-1]][i-1]);
                }
            }

            for(int i=0;i<qqqq;i++)
            {
                const auto [u, v] = queries[i];
                int lca = LCA(u, v);
                ans[i]=min({ans[i], 
                            getDist(u, lca, 1)+h1[u]-h2[lca]+h2[v]-h2[lca] + 1ll*T*iter,
                            getDist(v, lca, 0)+h1[u]-h1[lca]-h1[lca]+h2[v] + 1ll*T*iter});
            }
        }
        for(int i=0;i<qqqq;i++)
        {
            const auto [u, v] = queries[i];
            ans[i] = min(ans[i], h1[u]+h1[v]-2*h1[LCA(u, v)]);
            cout << ans[i] << '\n';
        }
    }
    return 0;
}