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
 
const int LOGN = 19;
const int N = 2e5+1;
int up[LOGN][N];
int cc[N];
int ff[N];
int depth[N];
vector<int> al[N];
 
void dfs(int u)
{
    for(auto v:al[u])
    {
        if(up[0][u]==v)
            continue;
        up[0][v]=u;
        depth[v]=depth[u]+1;
        dfs(v);
    }
}
 
int LCA(int u, int v)
{
    if(depth[u]>depth[v])
        swap(u, v);
    for(int i=LOGN-1;i>=0;i--)
    {
        if(depth[v]-(1<<i)<depth[u])
            continue;
        v = up[i][v];
    }
    for(int i=LOGN-1;i>=0&&u!=v;i--)
    {
        if(up[i][u]==up[i][v])
            continue;
        u = up[i][u];
        v = up[i][v];
    }
    if(u!=v)
        return up[0][v];
    return v;
}
 
// assumes v is ancestor of v
inline int getSum(int u, int v)
{
    return cc[u] - (depth[v]?cc[up[0][v]]:0);
}
 
int getFirst(int u, int v, int val)
{
    if(getSum(u, u)==val)
        return u;
    int upb = u;
    for(int i=LOGN-1;i>=0;i--)
    {
        if(depth[upb]-(1<<i)<depth[v]||getSum(u, up[i][upb])>=val)
            continue;
        upb = up[i][upb];
    }return up[0][upb];
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
        int n;
        cin>>n;
        vector<int> val(n);
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<LOGN;j++)
                up[j][i]=-1;
        for(int i=0;i<n;i++)
            al[i].clear();
        
        for(int i=0;i<n-1;i++)
        {
            int u, v;
            cin>>u>>v;
            u--, v--;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        depth[0]=0;
        dfs(0);
 
        for(int i=1;i<LOGN;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(up[i-1][j]==-1)
                    continue;
                up[i][j]=up[i-1][up[i-1][j]];
            }
        }
 
        vector<pair<int, int>> srt(n);
        for(int i=0;i<n;i++)
            srt[i] = {depth[i], i};
        sort(srt.begin(), srt.end());
 
        int q;
        cin>>q;
        vector<vector<pair<int, int>>> rngs(q);
        vector<int> ans(q, 0);
        vector<int> lcam(q, -1);
        vector<pair<int, int>> queries(q);
        for(int i=0;i<q;i++)
        {
            cin>>queries[i].first>>queries[i].second;
            queries[i].first--, queries[i].second--;
        }
        for(int i=0;i<31;i++)
        {
            cc[0] = (val[0]>>i)%2;
            ff[0] = ((val[0]>>i)%2?0:-1);
            for(int j=1;j<n;j++)
            {
                int u = srt[j].second;
                cc[u] = cc[up[0][u]] + (val[u]>>i)%2;
                ff[u] = ((val[u]>>i)%2?u:ff[up[0][u]]);
            }
 
            for(int j=0;j<q;j++)
            {
                const auto [u, v] = queries[j];
                if(lcam[j]==-1)
                    lcam[j] = LCA(u, v);
                int lca = lcam[j];
                int len = depth[u]-depth[lca]+depth[v]-depth[lca]+1;
                int totLeft = getSum(u, lca);
                int totRight = getSum(v, lca);
                int l=-1, r=-1;
                if(!totLeft&&!totRight)
                    continue;
                ans[j]++;
                if(totLeft)l = depth[u] - depth[ff[u]];
                if(totRight)r = len - (depth[v] - depth[ff[v]]) - 1;
                if(l==-1)l = len - (depth[v] - depth[getFirst(v, lca, totRight)]) - 1;
                if(r==-1)r = depth[u] - depth[getFirst(u, lca, totLeft)];
                assert(l!=-1&&r!=-1);
                rngs[j].emplace_back(l, r);
            }
        }
 
        for(int i=0;i<q;i++)
        {
            vector<pair<int, int>> tt;
            for(auto [l, r]: rngs[i])
            {
                tt.emplace_back(l, +1);
                tt.emplace_back(r+1, -1);
            }
            sort(tt.begin(), tt.end());
            int sm = 0, cr = 0;
            for(auto [_, upd]: tt)
                cr += upd, sm=max(sm, cr+ans[i]);
            ans[i] = sm;
        }
 
        for(int i=0;i<q;i++)
            cout << ans[i] << " \n"[i==q-1];
 
    }
    return 0;
}
