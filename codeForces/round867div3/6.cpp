#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void dfs1(vector<vector<int>> &al, vector<int> &parent, vector<ll> &mxDist, int k, int u)
{
    ll mxDown = 0;
    for(auto v: al[u])
    {
        if(parent[u]==v)continue;
        parent[v]=u;
        dfs1(al, parent, mxDist, k, v);
        mxDown = max(mxDown, mxDist[v]+k);
    }
    mxDist[u]=mxDown;
}

void dfs2(vector<vector<int>> &al, vector<int> &parent, vector<ll> &mxDist, int u, ll upMx, ll penalty, int c, int k, ll &ans)
{
    ans = max(ans, max(upMx, mxDist[u])-penalty);
    ll top[2] = {-1,-1};
    for(auto v:al[u])
    {
        if(parent[u]==v)continue;
        if(top[1]<mxDist[v])top[1]=mxDist[v];
        if(top[1]>top[0])swap(top[1], top[0]);
    }
    for(auto v:al[u])
    {
        if(parent[u]==v)continue;
        ll otherDownMax = (top[0]==mxDist[v])?top[1]:top[0];
        if(otherDownMax==-1)otherDownMax=-2ll*k;
        ll tUpMx = max(upMx+k, otherDownMax+2ll*k);
        dfs2(al, parent, mxDist, v, tUpMx, penalty+c, c, k, ans);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n, k, c;
        cin>>n>>k>>c;
        vector<vector<int>> al(n);
        for(int i=0;i<n-1;i++)
        {
            int u, v;
            cin>>u>>v;
            --u,--v;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        vector<int> parent(n, -1);
        vector<ll> mxDist(n);
        ll ans = 0;
        dfs1(al, parent, mxDist, k, 0);
        dfs2(al, parent, mxDist, 0, 0, 0, c, k, ans);
        cout << ans << '\n';
    }

    return 0;
}