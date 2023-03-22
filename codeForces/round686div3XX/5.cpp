#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;

bool dfs(vector<vector<int>> &al, vector<bool> &on, vector<int> &path, int node, vector<bool> &inCycle)
{
    if(on[node])
    {
        for(int i=path.size()-1;i>=0;i--)
        {
            inCycle[path[i]]=true;
            if(path[i]==node)break;
        }
        return true;
    }
    on[node]=true;
    path.push_back(node);
    for(auto u:al[node])
    {
        if(path.size()>=2&&path[path.size()-2]==u)continue;
        if(dfs(al, on, path, u, inCycle))return true;
    }
    on[node]=false;
    path.pop_back();
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> al(n);
        for(int i=0;i<n;i++)
        {
            int u, v;
            cin>>u>>v;
            --u,--v;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        vector<bool> inCycle(n, false);
        vector<bool> on(n, false);
        vector<int> path;
        assert(dfs(al, on, path, 0, inCycle));
        vector<int> stk;
        vector<bool> vis(n, false);
        ll ans = 0;
        for(int i=0;i<n;i++)
        {
            if(inCycle[i])
            {
                vis[i]=true;
                int cnt=1;
                stk.push_back(i);
                while(!stk.empty())
                {
                    int u = stk.back();
                    stk.pop_back();
                    for(auto v:al[u])
                    {
                        if(!inCycle[v]&&!vis[v])
                        {
                            cnt++;
                            stk.push_back(v);
                            vis[v]=true;
                        }
                    }
                }
                ans += 1ll*cnt*(cnt-1);
                ans += 2ll*cnt*(n-cnt);
            }
        }
        cout << ans/2 << '\n';
    }
    return 0;
}