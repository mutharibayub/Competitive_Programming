#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <algorithm>

using namespace std;

bool outOfRange(int r, int c, int R, int C)
{
    return r<0||c<0||r>=R||c>=C;
}

void calc(vector<vector<int>> &dp, int r, int c)
{
    if(dp[r][c]>=0)return;
    int R = dp.size();
    int C = dp[0].size();
    char cc = dp[r][c];
    int cy=0,cx=0;
    cy+=cc==-3;
    cy-=cc==-1;
    cx-=cc==-4;
    cx+=cc==-2;
    int nr = r+cy, nc = c+cx;
    if(outOfRange(nr,nc,R,C))
    {
        dp[r][c]=1;
    }    
    else
    {
        if(dp[nr][nc]<=-1)calc(dp,nr,nc);
        dp[r][c]=dp[nr][nc]+1;
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
        int n,m;
        cin>>n>>m;
        vector<vector<int>> done(n,vector<int>(m,0));
        vector<vector<int>> dp(n,vector<int>(m));
        int iterCount = 0;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
            {
                dp[i][j]=s[j]=='U'?-1:
                            s[j]=='R'?-2:
                                s[j]=='D'?-3:-4;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(done[i][j])continue;
                iterCount++;
                array<int,2> start = {i,j};
                array<int,2> coord = start;
                vector<array<int,2>> coords = {start};
                done[coord[0]][coord[1]]=iterCount;
                bool cycle = false;
                while(1)
                {
                    int cc = dp[coord[0]][coord[1]];
                    int cy=0,cx=0;
                    cy+=cc==-3;
                    cy-=cc==-1;
                    cx-=cc==-4;
                    cx+=cc==-2;
                    coord[0]+=cy,coord[1]+=cx;
                    if(outOfRange(coord[0],coord[1],n,m))break;
                    if(done[coord[0]][coord[1]]==iterCount)
                    {
                        cycle=true;
                        start=coord;
                        break;
                    }
                    if(done[coord[0]][coord[1]])break;
                    coords.push_back(coord);
                    done[coord[0]][coord[1]]=iterCount;
                }
                if(cycle)
                {
                    reverse(coords.begin(),coords.end());
                    while(coords.back()!=start)coords.pop_back();
                    for(auto coord:coords)
                    {
                        dp[coord[0]][coord[1]]=coords.size();
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]<0)
                {
                    vector<array<int,2>> stk;
                    stk.push_back({i,j});
                    while(!stk.empty())
                    {
                        int r = stk.back()[0];
                        int c = stk.back()[1];
                        char cc = dp[r][c];
                        int cy=0,cx=0;
                        cy+=cc==-3;
                        cy-=cc==-1;
                        cx-=cc==-4;
                        cx+=cc==-2;
                        int nr = r+cy, nc = c+cx;
                        if(outOfRange(nr,nc,n,m))
                        {
                            dp[r][c]=1;
                            stk.pop_back();
                        }    
                        else
                        {
                            if(dp[nr][nc]<=-1)
                            {
                                stk.push_back({nr,nc});
                            }
                            else
                            {
                                dp[r][c]=dp[nr][nc]+1;
                                stk.pop_back();
                            }
                        }                 
                    }
                }
            }
        }
        int ans = 0;
        int ansr = -1;
        int ansc = -1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]<=-1)calc(dp,i,j);
                if(dp[i][j]>ans)
                {
                    ans = dp[i][j];
                    ansr = i;
                    ansc = j;
                }
            }
        }
        cout << ansr+1 << ' ' << ansc+1 << ' ' << ans << '\n';
    }

    return 0;
}