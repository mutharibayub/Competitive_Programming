#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

const int N=2e5+1;

int parent[N];
int depth[N];
vector<int> al[N];

void dfs(int u)
{
    for(auto v:al[u])
    {
        if(parent[u]!=v)
        {
            parent[v]=u;
            depth[v]=depth[u]+1;
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
        int n;
        cin>>n;
        for(int i=0;i<n;i++)al[i].clear();
        for(int i=1;i<n;i++)
        {
            int v;
            cin>>v;
            --v;
            al[i].push_back(v);
            al[v].push_back(i);
        }
        vector<ll> score(n,0);
        vector<int> arr(n);
        for(int i=1;i<n;i++)cin>>arr[i];
        parent[0]=-1;
        depth[0]=0;
        dfs(0);
        map<int,vector<int>> nodes;
        for(int i=0;i<n;i++)nodes[depth[i]].push_back(i);
        for(auto iter=nodes.rbegin();iter->first>0;iter++)
        {
            vector<array<int,2>> srt;
            map<ll,int> m1,m2;
            for(auto node:iter->second)
            {
                srt.push_back({arr[node],node});
            }
            sort(srt.begin(),srt.end());
            int offset=0;
            for(auto u:srt)
            {
                m2[u[0]+score[u[1]]]++;
            }
            for(auto u:srt)
            {
                offset=u[0];

                ll nxt = max({srt.back()[0]-u[0]+score[u[1]],
                                u[0]-srt.front()[0]+score[u[1]],
                                m2.size()?prev(m2.end())->first-offset:0,
                                m1.size()?prev(m1.end())->first+offset:0});
                score[parent[u[1]]] = max(score[parent[u[1]]], nxt);
                m2[u[0]+score[u[1]]]--;
                if(!m2[u[0]+score[u[1]]])m2.erase(u[0]+score[u[1]]);
                m1[-u[0]+score[u[1]]]++;
            }
        }
        cout << score[0] << '\n';
    }

    return 0;
}