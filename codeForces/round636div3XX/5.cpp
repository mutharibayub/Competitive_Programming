#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(vector<vector<int>> &al, int start, vector<int> &dist)
{
    int n = al.size();
    vector<bool> done(n, false);
    queue<int> q;
    dist[start]=0;
    q.push(start);
    done[start]=true;
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(auto u:al[top])
        {
            if(!done[u])
            {
                done[u]=true;
                dist[u]=dist[top]+1;
                q.push(u);
            }
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
        int n, m;
        vector<int> pts(3);
        cin>>n>>m;
        for(int i=0;i<3;i++)
        {
            cin>>pts[i];
            --pts[i];
        }
        vector<long long> weights(m);
        for(int i=0;i<m;i++)cin>>weights[i];
        vector<vector<int>> al(n);
        for(int i=0;i<m;i++)
        {
            int u, v;
            cin>>u>>v;
            --u,--v;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        sort(weights.begin(), weights.end());
        for(int i=1;i<weights.size();i++)weights[i]+=weights[i-1];

        vector<vector<int>> dist(3, vector<int>(n));
        for(int i=0;i<3;i++)BFS(al, pts[i], dist[i]);
        
        long long ans = 1e18+7;
        for(int i=0;i<n;i++)
        {
            int overlapping = dist[1][i];
            int other = dist[0][i]+dist[2][i];
            if(overlapping+other>m)continue;
            long long overlappingWeight = overlapping?weights[overlapping-1]:0;
            long long otherWeight = (other+overlapping?weights[other+overlapping-1]:0)-overlappingWeight;
            overlappingWeight *= 2;
            ans = min(ans, overlappingWeight+otherWeight);
        }
        cout << ans << '\n';
    }
    return 0;
}