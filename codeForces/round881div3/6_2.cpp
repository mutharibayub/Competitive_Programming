#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <array>
#include <cassert>

using namespace std;

struct node
{
    int umx=-1;
    int dmx=-1;
    int mx=-1;
    int umn=-1;
    int dmn=-1;
    int mn=-1;
    int sm=-1;
    int top=-1;
};

void dfs(vector<vector<int>> &al, vector<vector<node>> &up, vector<int> &depth, int u)
{
    for(auto v:al[u])
    {
        if(up[u][0].top == v)continue;
        up[v][0].top=u;
        depth[v]=depth[u]+1;
        dfs(al, up, depth, v);
    }
}

node merge(node a, node b)
{
    node tmp;
    tmp.sm=a.sm+b.sm;
    tmp.dmn=min(a.dmn, a.sm+b.dmn);
    tmp.mn=min({a.mn, b.mn, a.umn+b.dmn});
    tmp.umn=min(b.umn, b.sm+a.umn);
    tmp.dmx=max(a.dmx, a.sm+b.dmx);
    tmp.mx=max({a.mx, b.mx, a.umx+b.dmx});
    tmp.umx=max(b.umx, b.sm+a.umx);
    tmp.top=b.top;
    return tmp;
}

int inSubSeg(vector<vector<node>> &up, vector<int> &depth, int u, int v, int k)
{
    if(u==v)
    {
        return up[u][0].mn<=k&&up[u][0].mx>=k;
    }

    if(depth[u]<depth[v])swap(u, v);
    node a = up[u][0], b = up[v][0];
    
    if(depth[u]==depth[v])
    {
        b = merge(b, up[ up[v][0].top ][0]);
        v = up[v][0].top;
    }
    
    for(int i=18;i>=0;i--)
    {
        if(depth[u]-(1<<i) > depth[v])
        {
            a = merge(a, up[ up[u][0].top ][i]);
            u = up[u][i].top;
        }
    }
    for(int i=18;i>=0;i--)
    {
        if(up[ up[u][0].top ][i].top!=up[v][i].top)
        {
            a = merge(a, up[ up[u][0].top ][i]);
            b = merge(b, up[ up[v][0].top ][i]);
            u = up[u][i].top;
            v = up[v][i].top;
        }
    }
    if(up[u][0].top!=v)
    {
        a = merge(a, up[ up[u][0].top ][0]);
        b = merge(b, up[ up[v][0].top ][0]);
        u = up[u][0].top, v = up[v][0].top;
    }
    int mx = max({a.mx, b.mx, a.umx+b.umx});
    int mn = min({a.mn, b.mn, a.umn+b.umn});
    return mn<=k&&mx>=k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int e;
        cin>>e;
        vector<pair<int,int>> edges;
        vector<array<int,3>> query;
        vector<int> weight = {1};
        for(int i=0;i<e;i++) 
        {
            string tp;
            cin>>tp;
            if(tp=="+")
            {
                int v, x;
                cin>>v>>x;
                --v;
                edges.push_back({v, weight.size()});
                weight.push_back(x);
            }
            else
            {
                int u, v, k;
                cin>>u>>v>>k;
                --u,--v;
                query.push_back({u, v, k});
            }
        }
        int n = weight.size();
        vector<vector<int>> al(n);
        vector<vector<node>> up(n, vector<node>(19));
        vector<int> depth(n);
        depth[0]=0;
        for(auto edge: edges)
        {
            al[edge.first].push_back(edge.second);
            al[edge.second].push_back(edge.first);
        }
        for(int i=0;i<n;i++)
        {
            up[i][0].dmn=up[i][0].mn=up[i][0].umn = min(0, weight[i]);
            up[i][0].dmx=up[i][0].mx=up[i][0].umx = max(0, weight[i]);
            up[i][0].sm=weight[i];
            up[i][0].top=-1;
        }
        dfs(al, up, depth, 0);
        for(int i=1;i<19;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(depth[j]-(1<<i)+1 < 0)continue;
                up[j][i] = merge(up[j][i-1], up[up[j][i-1].top][i-1]);
            }
        }
        for(auto q:query)
        {
            cout << (inSubSeg(up, depth, q[0], q[1], q[2])?"YES":"NO") << '\n';
        }
    }

    return 0;
}