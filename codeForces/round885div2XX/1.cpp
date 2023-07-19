#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll pwr(ll n, ll e)
{
    ll o=1;
    while(e)
    {
        if(e%2)o=o*n%MOD;
        e/=2;
        n=n*n%MOD;
    }return o;
}

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, m, k;
        cin>>n>>m>>k;
        vector<vector<bool>> grid(n, vector<bool>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, -1));
        int r, c;
        cin>>r>>c;
        r--,c--;
        for(int i=0;i<k;i++)
        {
            int a, b;
            cin>>a>>b;
            a--, b--;
            grid[a][b]=true;
        }
        queue<array<int, 2>> q;
        dist[r][c]=0;
        q.push({r,c});
        bool ok = true;
        while(!q.empty())
        {
            array<int,2> top = q.front();
            // cout << top[0] << ' ' << top[1] << ' ' << dist[top[0]][top[1]] <<  ' ' << grid[top[0]][top[1]] << '\n';
            q.pop();
            if(dist[top[0]][top[1]]%2==0&&grid[top[0]][top[1]])
            {
                ok = false;
                break;
            }
            for(auto [i, j]: vector<array<int,2>>({{0,1},{1,0},{0,-1},{-1,0}}))
            {
                // cout << i << ' ' << j << '\n';
                if(top[0]+i>=0 && top[0]+i<n && top[1]+j>=0 && top[1]+j<m && dist[top[0]+i][top[1]+j]==-1)
                {
                    dist[top[0]+i][top[1]+j]=dist[top[0]][top[1]]+1;
                    q.push({top[0]+i, top[1]+j});
                }
            }
        }
        cout << (ok?"YES":"NO") << '\n';
    }    

    return 0;
}