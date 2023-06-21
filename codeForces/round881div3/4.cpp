#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(vector<vector<int>> &al, vector<int> &leaves, vector<int> &parent, int u)
{
    leaves[u]=0;
    for(auto v: al[u]) 
    {
        if(parent[u]==v)continue;
        parent[v]=u;
        dfs(al, leaves, parent, v);
        leaves[u]+=leaves[v];
    }
    if(u&&al[u].size()==1)leaves[u]=1;
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
        vector<int> parent(n);
        vector<int> leaves(n);
        parent[0]=-1;
        for(int i=0;i<n-1;i++)
        {
            int u, v;
            cin>>u>>v;
            --u,--v;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        dfs(al, leaves, parent, 0);
        int q;
        cin>>q;
        for(int i=0;i<q;i++) 
        {
            int x, y;
            cin>>x>>y;
            --x,--y;
            cout << 1ll*leaves[x]*leaves[y] << '\n';
        }
    }
    return 0;
}