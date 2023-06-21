#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<pair<int, int>>> &al, vector<int> &ans, vector<int> &size, vector<pair<int, int>> &parent, int u)
{
    for(auto pr: al[u])
    {
        int v=pr.first, idx=pr.second;
        if(parent[u].first==v)continue;
        parent[v]={u, idx};
        if(!dfs(al, ans, size, parent, v))return false;
        size[u] += size[v];
    }
    if(size[u]>3)return false;
    if(!u&&size[u]!=3)return false;
    if(u&&size[u]==3)
    {
        ans.push_back(parent[u].second);
        size[u]=0;
    }
    return true;
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
        vector<vector<pair<int, int>>> al(n);
        for(int i=0;i<n-1;i++)
        {
            int u, v;
            cin>>u>>v;
            --u,--v;
            al[u].push_back({v,i});
            al[v].push_back({u,i});
        } 
        vector<int> size(n, 1);
        vector<int> ans;
        vector<pair<int, int>> parent(n);
        parent[0]={-1,-1};
        if(dfs(al, ans, size, parent, 0))
        {
            cout << ans.size() << '\n';
            for(int i=0;i<ans.size();i++)
            {
                if(i)cout << ' ';
                cout << ans[i]+1;
            }cout << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }   

    return 0;
}