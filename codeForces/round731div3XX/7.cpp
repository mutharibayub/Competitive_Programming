#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

const int N = 4e5+1;
vector<int> al[N];
vector<int> invAl[N];
bool inCycle[N];
vector<int> comp[N];
vector<int> stk;
bool vis[N];

void dfs1(int u)
{
    vis[u]=true;
    for(auto v:al[u])
    {
        if(!vis[v])
        {
            dfs1(v);
        }
    }
    stk.push_back(u);
}

void dfs2(int u, int parent)
{
    vis[u]=true;
    comp[parent].push_back(u);
    for(auto v:invAl[u])
    {
        if(!vis[v])
        {
            dfs2(v, parent);
        }
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
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)al[i].clear(), invAl[i].clear(), comp[i].clear(), inCycle[i]=false;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            --u,--v; 
            if(u==v)
            {
                inCycle[u]=true;
                continue;
            }
            al[u].push_back(v);
            invAl[v].push_back(u);
        }
        stk.clear();
        for(int i=0;i<n;i++)vis[i]=false;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])dfs1(i);
        }
        for(int i=0;i<n;i++)vis[i]=false;
        while(!stk.empty())
        {
            dfs2(stk.back(), stk.back());
            while(!stk.empty()&&vis[stk.back()])stk.pop_back();
        }
        for(int i=0;i<n;i++)
        {
            if(comp[i].size()>=2)
            {
                for(auto v:comp[i])
                {
                    inCycle[v]=true;
                }
            }
        }
        queue<array<int,2>> qu;
        vector<int> ans(n, 0);
        qu.push({0, 0});
        while(!qu.empty())
        {
            int u = qu.front()[0];
            int parentVal=qu.front()[1];
            int curAns = ans[u];
            qu.pop();
            if(inCycle[u]||parentVal==-1)
            {
                ans[u]=-1;
            }
            else if(ans[u]!=-1)
            {
                ans[u]=min(ans[u]+1, 2);
            }
            if(ans[u]!=curAns)
            {
                for(auto v:al[u])
                {
                    qu.push({v, ans[u]});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << ans[i];
        }cout << '\n';
    }

    return 0;
}