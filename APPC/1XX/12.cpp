#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <array>

using namespace std;

typedef long long ll;

const int N = 1e5+1;
vector<int> al[N];
int parent[N];
int depth[N];
map<int,int> mp[N];
int p[N];

void dfs(int u)
{
    for(auto v:al[u])
    {
        if(parent[u]!=v)
        {
            parent[v]=u;
            depth[v]=depth[u]+1;
            dfs(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> color(n);
    vector<int> colorCount(n+1,0);
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        cin>>color[i];
        colorCount[color[i]]++;
    }
    for(int i=0;i<n;i++)p[i]=i;
    vector<array<int,2>> edges;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        al[u].push_back(v);
        al[v].push_back(u);
        edges.push_back({u,v});
    }
    depth[0]=0;
    for(int i=0;i<n;i++)parent[i]=-1;
    dfs(0);

    for(int i=0;i<n;i++)
    {
        ans[i]=colorCount[color[i]]-1;
        if(ans[i])mp[i][color[i]]++;
        p[i]=i;
    }

    vector<array<int,2>> nodes(n);
    for(int i=0;i<n;i++)nodes[i]={depth[i],i};
    sort(nodes.rbegin(), nodes.rend());

    for(int i=0;i<n-1;i++)
    {
        int depth = nodes[i][0];
        int node = nodes[i][1];

        int u=node;
        int v=parent[node];
        if(mp[p[u]].size()<mp[p[v]].size())
        {
            swap(u,v);
        }
        ll newAns=ans[u];
        for(auto c:mp[p[v]])
        {
            int color = c.first;
            int cnt = c.second;
            auto it = mp[p[u]].find(color);
            if(it!=mp[p[u]].end()&&it->second)
            {
                int cl = it->first;
                int clCnt = it->second;
                newAns-=1ll*(colorCount[cl]-clCnt)*clCnt;
            }
            int newCnt = (mp[p[u]][color]+=cnt);
            if(newCnt==colorCount[color])mp[p[u]].erase(color);
            else newAns+=1ll*(colorCount[color]-newCnt)*newCnt;
        }
        p[v]=p[u];
        ans[parent[node]]=newAns;
    }

    for(auto edge:edges)
    {
        int u=edge[0],v=edge[1];
        if(parent[u]==v)swap(u,v);
        cout << ans[v] << ' ';
    }
    cout<< endl;

    return 0;
}