#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void calc(vector<int> &dp, vector<vector<int>> &al, vector<vector<int>> &invAl, int node)
{
    int v=1;
    if(al[node].size()>1)
    for(auto adj:al[node])
    {
        if(invAl[adj].size()==1)continue;
        if(dp[adj]==-1)
        {
            calc(dp, al, invAl, adj);
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

    vector<int> dp(n,-1);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]==-1)calc(dp, al, invAl, i);
        ans=max(ans, dp[i]);
    }
    cout << ans << '\n';

    return 0;
}