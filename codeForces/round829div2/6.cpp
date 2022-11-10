#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <array>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll r,c,p,q;
    cin>>r>>c>>p>>q;

    vector<string> mat(r);
    vector<vector<ll>> dists(r, vector<ll>(c, 1e18+7));
    for(int i=0;i<r;i++)
    {
        cin >> mat[i];
    }

    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j]=='.')
            {
                pq.push({0, i, j});
                dists[i][j]=0;
            }
        }
    }

    while(!pq.empty())
    {
        array<ll, 3> top = pq.top();
        int y = top[1], x = top[2];
        ll dist = top[0];
        pq.pop();
        if(dists[y][x]<dist)continue;
        if(x>0)
        {
            if(mat[y][x-1]=='R' && dists[y][x-2]>dist+q)
            {
                dists[y][x-2]=dist+q;
                pq.push({dist+q, y, x-2});
            }
            else if(mat[y][x-1]=='U' && dists[y+1][x-1]>dist+p)
            {
                dists[y+1][x-1]=dist+p;
                pq.push({dist+p, y+1, x-1});
            }
            else if(mat[y][x-1]=='D' && dists[y-1][x-1]>dist+p)
            {
                dists[y-1][x-1]=dist+p;
                pq.push({dist+p, y-1, x-1});
            }
        }
        if(x<c-1)
        {
            if(mat[y][x+1]=='L' && dists[y][x+2]>dist+q)
            {
                dists[y][x+2]=dist+q;
                pq.push({dist+q, y, x+2});
            }
            else if(mat[y][x+1]=='U' && dists[y+1][x+1]>dist+p)
            {
                dists[y+1][x+1]=dist+p;
                pq.push({dist+p, y+1, x+1});
            }
            else if(mat[y][x+1]=='D' && dists[y-1][x+1]>dist+p)
            {
                dists[y-1][x+1]=dist+p;
                pq.push({dist+p, y-1, x+1});
            }
        }
        if(y>0)
        {
            if(mat[y-1][x]=='D' && dists[y-2][x]>dist+q)
            {
                dists[y-2][x]=dist+q;
                pq.push({dist+q, y-2, x});
            }
            else if(mat[y-1][x]=='L' && dists[y-1][x+1]>dist+p)
            {
                dists[y-1][x+1]=dist+p;
                pq.push({dist+p, y-1, x+1});
            }
            else if(mat[y-1][x]=='R' && dists[y-1][x-1]>dist+p)
            {
                dists[y-1][x-1]=dist+p;
                pq.push({dist+p, y-1, x-1});
            }
        }
        if(y<r-1)
        {
            if(mat[y+1][x]=='U' && dists[y+2][x]>dist+q)
            {
                dists[y+2][x]=dist+q;
                pq.push({dist+q, y+2, x});
            }
            else if(mat[y+1][x]=='L' && dists[y+1][x+1]>dist+p)
            {
                dists[y+1][x+1]=dist+p;
                pq.push({dist+p, y+1, x+1});
            }
            else if(mat[y+1][x]=='R' && dists[y+1][x-1]>dist+p)
            {
                dists[y+1][x-1]=dist+p;
                pq.push({dist+p, y+1, x-1});
            }
        }
    }

    // for(int i=0;i<r;i++)
    // {
    //     for(int j=0;j<c;j++)
    //     {
    //         cout << ((dists[i][j])>100000?-1:dists[i][j]) << "\t\t";
    //     }cout << '\n';
    // }

    ll ans = 1e18+7;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i<r-1)ans = min(ans, dists[i][j] + dists[i+1][j]);
            if(j<c-1)ans = min(ans, dists[i][j] + dists[i][j+1]);
        }
    }
    if(ans >= 1e18+7)ans = -1;
    cout << ans << '\n';

    return 0;
}
