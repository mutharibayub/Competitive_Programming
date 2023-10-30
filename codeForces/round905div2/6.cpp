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

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    // cin>>tttt;
    while(tttt--)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<pair<int, int>>> al(n);
        for(int i = 0; i < m; i++)
        {
            int mi;
            cin>>mi;
            for(int j = 0; j < mi; j++)
            {
                int u, v;
                cin >> u >> v;
                u--, v--;
                al[u].push_back({v, i});
                al[v].push_back({u, i});
            }
        }
        int k;
        cin>>k;
        vector<vector<int>> points(m);
        for(int i = 0; i < k; i++)
        {
            int a;
            cin >> a;
            a--;
            points[a].push_back(i);
        }
        vector<int> dist(n, 1e9+7);
        minPQ<pair<int, int>> pq;
        pq.push({0, 0});
        while(!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            dist[u] = w;
            for(auto [v, loc]: al[u])
            {
                if(dist[v] != 1e9+7)
                    continue;
                auto nxt = lower_bound(points[loc].begin(), points[loc].end(), w);
                if (nxt==points[loc].end())
                    continue;
                pq.push({*nxt+1, v});
            } 
            while(!pq.empty() && pq.top().first >= dist[pq.top().second])
                pq.pop();
        }

        cout << (dist[n-1] == (1e9+7)? -1: max(1, dist[n-1])) << '\n';

    }
    return 0;
}