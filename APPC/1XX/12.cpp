#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> colors(n);
    vector<int> color(n);
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        tmp--;
        color[i]=tmp;
        colors[tmp].push_back(i);
    }
    vector<pair<int,int>> edges;
    
    vector<vector<int>> adjList(n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        edges.emplace_back(a,b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<int> depth(n,-1);
    vector<int> parent(n);
    
    {
        vector<array<int,3>> stk;
        stk.push_back({0,0,-1});
        while(!stk.empty())
        {
            array<int,3> tmp = stk.back();
            stk.pop_back();
            depth[tmp[0]]=tmp[1];
            parent[tmp[0]]=tmp[2];
            for(auto &it:adjList[tmp[0]])
            {
                if(depth[it]==-1)
                {
                    stk.push_back({it, tmp[1]+1, tmp[0]});
                }
            }
        }
    }

    unordered_map<int64_t, int64_t> counts;
    counts.reserve(n-1);

    for(int i=0;i<n;i++)
    {
        if(colors[i].size()<2)continue;
        vector<int> found(n,0);
        vector<bool> done(n,false);
        priority_queue<array<int,2>, vector<array<int,2>>> pq;
        for(auto &it:colors[i])
        {
            pq.push({depth[it], it});
            found[it]=1;
        }
        while(!pq.empty())
        {
            array<int,2> top = pq.top();
            pq.pop();
            int node = top[1], dpth=top[0];
            if(done[node])continue;
            while(parent[node]!=-1 && dpth>=pq.top()[0] && colors[i].size()-found[node]>0)
            {
                counts[node*1e5+parent[node]] += found[node]*(colors[i].size()-found[node]);
                found[parent[node]] = found[node]+found[parent[node]];
                done[node]=true;
                node = parent[node];
                dpth = depth[node];
            }   
            if(parent[node]!=-1 && colors[i].size()-found[node]>0)pq.push({dpth, node});
        }
    }   
    
    vector<int> ans(n-1);
    for(int i=0;i<n-1;i++)
    {
        ans[i] = max(counts[edges[i].first*1e5+edges[i].second], counts[edges[i].second*1e5+edges[i].first]);
        if(i)cout << ' ';
        cout << ans[i];
    }cout << '\n';


    return 0;
}