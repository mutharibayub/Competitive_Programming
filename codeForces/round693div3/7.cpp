#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int calc(vector<vector<int>> &al, vector<int> &d, vector<int> &dp, int u)
{
    if(dp[u]==-1)
    {
        int val = d[u];
        for(auto v:al[u])
        {
            if(d[v]<=d[u])
            {
                val=min(val, d[v]);
            }
            else
            {
                val=min(val, calc(al, d, dp, v));
            }
        }
        dp[u]=val;
    }
    return dp[u];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--) 
    {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> al(n);
        for(int i=0;i<m;i++)
        {
            int u, v; 
            cin>>u>>v;
            --u,--v;
            al[u].push_back(v);
        }
        vector<int> d(n, -1);
        d[0]=0;
        queue<int> q;
        q.push(0);
        while(q.size())
        {
            int u = q.front();
            q.pop();
            for(auto v:al[u])
            {
                if(d[v]==-1)
                {
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        vector<int> dp(n, -1);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << calc(al, d, dp, i);;
        }cout << '\n';
    }

    return 0;
}