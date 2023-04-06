#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        vector<set<int>> al(n);
        for(int i=0;i<n-1;i++)
        {
            int u, v;
            cin>>u>>v;
            --u,--v;
            al[u].insert(v);
            al[v].insert(u);
        }
        vector<vector<int>> leaves(n);
        for(int i=0;i<n;i++)
        {
            if(al[i].size()==1)
            {
                leaves[*al[i].begin()].push_back(i);
            }
        }
        int ans = 0;
        priority_queue<array<int,2>> pq;
        for(int i=0;i<n;i++)pq.push({(int)leaves[i].size(), i});
        while(pq.size()&&pq.top()[0]>=k)
        {
            int node = pq.top()[1];
            pq.pop();
            while(leaves[node].size()>=k)
            {
                for(int i=0;i<k;i++)
                {
                    al[node].erase(leaves[node].back());
                    al[leaves[node].back()].clear();
                    leaves[leaves[node].back()].clear();
                    leaves[node].pop_back();
                }
                ans += 1;
            }
            if(al[node].size()==1)
            {
                leaves[*al[node].begin()].push_back(node);
                pq.push({(int)leaves[*al[node].begin()].size(), *al[node].begin()});
            }
            pq.push({(int)leaves[node].size(), node});
            while(pq.size() && leaves[pq.top()[1]].size()!=pq.top()[0])pq.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}