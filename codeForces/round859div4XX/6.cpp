#include <iostream>
#include <vector>
#include <array>

using namespace std;

int getInd(array<int, 2> &dir)
{
    return (dir[0]==1)*2+(dir[1]==1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        array<int,2> s,e;
        int n, m;
        cin>>n>>m>>s[0]>>s[1]>>e[0]>>e[1];
        string dir;
        cin>>dir;
        array<int,2> dd = {dir[0]=='U'?-1:1, dir[1]=='L'?-1:1};
        s[0]--,s[1]--,e[0]--,e[1]--;
        vector<vector<array<bool, 4>>> vis(n, vector<array<bool,4>>(m, {0,0,0,0}));
        vis[s[0]][s[1]][getInd(dd)]=true;
        int bounce = 0;
        while(s!=e)
        {
            bool bnc = false;
            array<int,2> nxt = {s[0]+dd[0],s[1]+dd[1]};
            if(nxt[0]>=n||nxt[0]<0)dd[0]*=-1, nxt={s[0]+dd[0],s[1]+dd[1]}, bnc=true;
            if(nxt[1]>=m||nxt[1]<0)dd[1]*=-1, nxt={s[0]+dd[0],s[1]+dd[1]}, bnc=true;
            if(vis[nxt[0]][nxt[1]][getInd(dd)])
            {
                bounce=-1;
                break;
            }
            vis[nxt[0]][nxt[1]][getInd(dd)]=true;
            s=nxt;
            bounce+=bnc;
        }
        cout << bounce << '\n';
    }
    return 0;
}