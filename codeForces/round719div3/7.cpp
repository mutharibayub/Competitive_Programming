#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, w;
    cin>>n>>m>>w;
    
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }

    ll ans = 1e18;
    ll t1=1e18, t2=1e18; 
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<array<int,3>> q;
    
    q.push({0,0,0});
    vis[0][0]=true;
    if(grid[0][0]>0)
    {
        t1=min(t1, 1ll*grid[0][0]);
    }
    while(q.size())
    {
        array<int, 3> top = q.front();
        q.pop();
        for(auto chg:vector<array<int,2>>({{0,1},{0,-1},{1,0},{-1,0}}))
        {
            array<int, 3> nxt = top;
            nxt[2]++,nxt[0]+=chg[0],nxt[1]+=chg[1];
            if(nxt[0]<0||nxt[0]>=n||nxt[1]<0||nxt[1]>=m||vis[nxt[0]][nxt[1]])continue;
            int cellVal = grid[nxt[0]][nxt[1]];
            if(cellVal==-1)continue;
            vis[nxt[0]][nxt[1]]=true;
            if(cellVal>0)
            {
                t1=min(t1, nxt[2]*1ll*w+cellVal);
            }
            if(nxt[0]==n-1&&nxt[1]==m-1)ans=min(ans, nxt[2]*1ll*w);
            q.push(nxt);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vis[i][j]=false;
        }
    }

    q.push({n-1,m-1,0});
    vis[n-1][m-1]=true;
    if(grid[n-1][m-1]>0)
    {
        t2=min(t2, 1ll*grid[n-1][m-1]);
    }
    while(q.size())
    {
        array<int, 3> top = q.front();
        q.pop();
        for(auto chg:vector<array<int,2>>({{0,1},{0,-1},{1,0},{-1,0}}))
        {
            array<int, 3> nxt = top;
            nxt[2]++,nxt[0]+=chg[0],nxt[1]+=chg[1];
            if(nxt[0]<0||nxt[0]>=n||nxt[1]<0||nxt[1]>=m||vis[nxt[0]][nxt[1]])continue;
            int cellVal = grid[nxt[0]][nxt[1]];
            if(cellVal==-1)continue;
            vis[nxt[0]][nxt[1]]=true;
            if(cellVal>0)
            {
                t2=min(t2, nxt[2]*1ll*w+cellVal);
            }
            q.push(nxt);
        }
    }

    if(t1!=1e18&&t2!=1e18)ans = min(ans, t1+t2);

    cout << (ans==1e18?-1:ans) << '\n';

    return 0;
}