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
#include <string>

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
        cin >> n >> m;
        int one_count = 0;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
                one_count += grid[i][j];
            }
        }
        vector<int> row_count(n);
        vector<int> col_count(m);
        int in_flow = 0, out_flow = 0;
        for(int i = 0; i < n; i++) {
            cin >> row_count[i];
            in_flow += row_count[i];
        }
        for(int i = 0; i < m; i++) {
            cin >> col_count[i];
            out_flow += col_count[i];
        }

        if(in_flow != out_flow) {
            cout << -1 << '\n';
            continue;
        }

        int start = 100;
        int end = 101;

        vector<vector<int>> flow(100+2, vector<int>(100+2, 0));
        vector<vector<int>> cost(100+2, vector<int>(100+2, 0));
        for(int i = 0; i < n; i++) {
            flow[start][i] = row_count[i];
        }
        for(int i = 0; i < m; i++) {
            flow[50+i][end] = col_count[i];
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                flow[i][50+j] = 1;
                cost[i][50+j] = grid[i][j] == 0;
                cost[50+j][i] = -1*(grid[i][j] == 0);
            }
        }

        int ans = 0, total_flow = 0;
        while(true) {
            vector<int> dist(100+2, 1e9);
            vector<int> parent(100+2, -1);
            queue<int> pq;
            vector<bool> inQ(100+2, 0);
            inQ[start] = true;
            dist[start] = 0;
            pq.push(start);
            while(!pq.empty()) {
                int u = pq.front();
                pq.pop();
                inQ[u] = false;
                for(int v = 0; v < 100+2; v++) {
                    if(!flow[u][v]) {
                        continue;
                    }
                    if(dist[u] + cost[u][v] < dist[v]) {
                        dist[v] = dist[u] + cost[u][v];
                        parent[v] = u;
                        if(!inQ[v]) {
                            pq.push(v);
                            inQ[v] = true;
                        }
                    }
                }
            }
            if(parent[end] == -1) {
                break;
            }
            int cur = end;
            while(parent[cur] != -1) {
                flow[parent[cur]][cur]--;
                flow[cur][parent[cur]]++;
                cur = parent[cur];
            }
            ans += dist[end];
            total_flow++;
        }

        if(total_flow != in_flow) {
            cout << -1 << '\n';
            continue;
        }

        cout << 2*ans + one_count - total_flow << '\n';
    }
    return 0;
}