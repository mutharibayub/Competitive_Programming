#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5+1;
vector<int> al[N];
int dist[N];
int parent[N];
int marked[N];
int ans = 1e9;

void dfs(int u)
{
    dist[u] = marked[u]?0:-1;
    for(auto v: al[u])
    {
        if(parent[u] == v)
            continue;
        parent[v] = u;
        dfs(v);
        dist[u] = max(dist[u], dist[v]==-1?-1:dist[v]+1);
    }
}

void dfs1(int u, int above)
{
    map<int, int> mp;
    mp[above]++;
    for(auto v: al[u])
    {
        if(parent[u] == v)
            continue;

        mp[dist[v]]++;
    }

    int posDist = prev(mp.end())->first==-1?-1:prev(mp.end())->first+1;
    if(posDist == -1 && marked[u])
        posDist = 0;
    ans = min(ans, posDist);

    for(auto v: al[u])
    {
        if(parent[u] == v)
            continue;

        mp[dist[v]]--;
        if(!mp[dist[v]])
            mp.erase(dist[v]);
        
        int aboveDist = prev(mp.end())->first==-1?-1:prev(mp.end())->first+1;
        if (aboveDist == -1 && marked[u])
            aboveDist = 0;
        dfs1(v, aboveDist);

        mp[dist[v]]++;
    }
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, k;
        cin>>n>>k;

        ans = 1e9+7;
        for(int i=0; i<n; i++)
        {
            marked[i]=0;
            parent[i]=-1;
            dist[i]=0;
            al[i].clear();
        }

        for(int i=0; i<k; i++)
        {
            int tmp;
            cin>>tmp;
            tmp--;
            marked[tmp]=1;
        }

        for(int i=0; i<n-1; i++)
        {
            int u, v;
            cin>>u>>v;
            u--, v--;
            al[u].push_back(v);
            al[v].push_back(u);
        }

        dfs(0);
        dfs1(0, -1);
        
        cout << ans << '\n';
        
    }
    return 0;
}