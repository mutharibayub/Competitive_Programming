#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void calc(vector<int> &dp, vector<vector<int>> &al, int node)
{
    int v=1;
    for(auto adj:al[node])
    {
        if(dp[adj]==-1)
        {
            calc(dp, al, adj);
        }
        v=max(v, 1+dp[adj]);
    }
    dp[node]=v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> al(n);
    vector<vector<int>> invAl(n);
    vector<array<int,2>> toRemove;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        al[a].push_back(b);
        invAl[b].push_back(a);
    }

    for(int i=0;i<n;i++)
    {
        if(al[i].size()==1)al[i].pop_back();
        if(invAl[i].size()==1)toRemove.push_back({invAl[i][0],i});
    }
    sort(toRemove.begin(), toRemove.end());
    for(int i=0,j=0;i<n;i++)
    {
        sort(al[i].begin(), al[i].end());
        if(j<toRemove.size() && toRemove[j][0]==i)
        {
            vector<int> tmp;
            for(auto adj:al[i])
            {
                while(j<toRemove.size() && toRemove[j][0]==i && toRemove[j][1]<adj)j++;
                if(j<toRemove.size() && toRemove[j][0]==i && toRemove[j][1]==adj)continue;
                tmp.push_back(adj);
            }
            al[i]=tmp;
        }
    }

    vector<int> dp(n,-1);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]==-1)calc(dp, al, i);
        ans=max(ans, dp[i]);
    }
    cout << ans << '\n';

    return 0;
}