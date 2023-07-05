#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <set>

using namespace std;

const int N = 2e5+1;
vector<int> al[N];
int parent[N];

void dfs(int u)
{
    for(auto v:al[u])
    {
        if(parent[u]!=v)
        {
            parent[v]=u;
            dfs(v);
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
        int n,s;
        cin>>n>>s;
        s--;
        for(int i=0;i<n;i++)al[i].clear();
        vector<int> nearest(n,1e9+7);
        vector<int> arr(n);
        arr[0]=s;
        for(int i=1;i<n;i++)
        {
            cin>>arr[i];
            arr[i]--;
        }
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        parent[0]=-1;
        dfs(0);
        int ans=1e9+7;
        for(int i=0;i<n;i++)
        {
            int u = arr[i];
            int dist = 0;
            while(u!=-1&&dist<=ans)
            {
                ans=min(ans,nearest[u]+dist);
                nearest[u]=min(nearest[u],dist);
                dist++;
                u=parent[u];
            }
            if(i)
            {
                cout << ans << ' ';
            }
        }cout << '\n';
    }

    return 0;
}