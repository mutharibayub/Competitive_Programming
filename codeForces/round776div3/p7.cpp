#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <assert.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,s,e;
        cin>>n>>m>>s>>e;
        s--,e--;
        vector<vector<int>> al(n);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            al[a].push_back(b);
            al[b].push_back(a);
        }
        vector<int> shortest(n,1e9+7);
        vector<array<ll,2>> counts(n,{0,0});
        queue<array<int,2>> q;
        vector<bool> vis(n,false);
        q.push({s,0});
        shortest[s]=0;
        vis[s]=true;
        while(!q.empty())
        {
            int top = q.front()[0];
            int dist = q.front()[1];
            q.pop();
            for(auto neigh:al[top])
            {
                if(vis[neigh])continue;
                if(shortest[neigh]>shortest[top]+1)
                {
                    shortest[neigh]=shortest[top]+1;
                    q.push({neigh,shortest[neigh]});
                    vis[neigh]=true;
                }
            }
        }
        for(int i=0;i<n;i++)vis[i]=false;
        counts[s][0]=1;
        q.push({s,0});
        vis[s]=true;
        while(!q.empty())
        {
            int top = q.front()[0];
            int dist = q.front()[1];
            q.pop();
            if(dist==shortest[top])q.push({top,shortest[top]+1});
            for(auto neigh:al[top])
            {
                if(dist==shortest[top])
                {
                    if(shortest[top]+1==shortest[neigh])
                    {
                        counts[neigh][0]+=counts[top][0];
                        counts[neigh][0]%=MOD;
                        if(!vis[neigh])
                        {
                            q.push({neigh,shortest[neigh]});
                            vis[neigh]=true;
                        }
                    }
                    if(shortest[top]+1==shortest[neigh]+1)
                    {
                        counts[neigh][1]+=counts[top][0];
                        counts[neigh][1]%=MOD;   
                    }
                }
                else if(dist==shortest[top]+1)
                {
                    if(shortest[top]+2==shortest[neigh]+1)
                    {
                        counts[neigh][1]+=counts[top][1];
                        counts[neigh][1]%=MOD;
                    }
                }
                else assert(false);
            }
        }
        cout << (counts[e][0] + counts[e][1])%MOD << '\n';
    }
}