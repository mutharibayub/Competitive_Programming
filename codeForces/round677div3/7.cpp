#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<array<int,2>>> al(n);
    vector<vector<int>> dist(n, vector<int>(n));
    vector<array<int,3>> edges;

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        --u,--v;
        al[u].push_back({v,w});
        al[v].push_back({u,w});
        edges.push_back({u, v, w});
    }

    for(int s=0;s<n;s++)
    {
        priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>> pq;
        vector<bool> done(n, false);
        pq.push({0, s});
        while(!pq.empty())
        {
            int u = pq.top()[1];
            int dt = pq.top()[0];
            done[u]=true;
            dist[s][u]=dt;
            for(auto node:al[u])
            {
                int v = node[0];
                int w = node[1];
                if(!done[v]) 
                {
                    pq.push({dt+w, v});
                }
            }
            while(pq.size()&&done[pq.top()[1]])pq.pop();
        }
    }

    vector<array<int,2>> routes(k);
    for(int i=0;i<k;i++)
    {
        cin>>routes[i][0]>>routes[i][1];
        --routes[i][0],--routes[i][1];
    }

    int ans = 1e9+7;

    for(auto edge:edges)
    {
        int e1 = edge[0], e2 = edge[1];
        int sum = 0;
        for(int i=0;i<k;i++)
        {
            int u = routes[i][0], v = routes[i][1];
            int minDist = min({dist[u][v], dist[u][e1]+dist[e2][v], dist[u][e2]+dist[e1][v]});
            sum+=minDist;
        }
        ans = min(ans, sum);
    }

    cout << ans << '\n';

    return 0;
}