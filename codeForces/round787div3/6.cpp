#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &al, vector<int> &parent, vector<int> &depth, int node)
{
    for(int i=0;i<al[node].size();i++)
    {
        if(depth[al[node][i]]==-1)
        {
            depth[al[node][i]]=depth[node]+1;
            parent[al[node][i]]=node;
            dfs(al,parent,depth,al[node][i]);
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
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        x--,y--;
        set<int> toVisit;
        for(int i=0;i<k;i++)
        {
            int a;
            cin>>a;
            a--;
            toVisit.insert(a);
        }
        vector<vector<int>> al(n);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            al[a].push_back(b);
            al[b].push_back(a);
        }
        vector<int> depth(n,-1);
        vector<int> parent(n,-1);
        depth[x]=0;
        dfs(al,parent,depth,x);
        int last=-1;
        int ans=0;
        vector<int> dp(n,-1);
        vector<pair<int,int>> ord(n);
        for(int i=0;i<n;i++)ord[i]={depth[i],i};
        sort(ord.rbegin(),ord.rend());
        for(int i=0;i<n;i++)
        {
            int node = ord[i].second;
            dp[node]=0;
            for(int i=0;i<al[node].size();i++)
            {
                int neigh = al[node][i];
                if(depth[neigh]<depth[node])continue;
                if(dp[neigh])dp[node]+=dp[neigh];
            }
            if(dp[node]||toVisit.find(node)!=toVisit.end())dp[node]+=2;
        }
        while(1)
        {
            for(int i=0;i<al[y].size();i++)
            {
                if(depth[y]>depth[al[y][i]] || al[y][i]==last)continue;
                ans+=dp[al[y][i]];
            }
            if(y==x)break;
            last=y;
            ans++;
            y=parent[y];
        }
        cout << ans << '\n';
    }

    return 0;
}