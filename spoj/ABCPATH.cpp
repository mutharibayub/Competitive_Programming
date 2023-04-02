#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int t=0;;t++)
    {
        int n, m;
        cin>>n>>m;
        if(!n&&!m)break;
        cout << "Case " << t+1 << ": ";
        vector<string> grid(n);
        for(int i=0;i<n;i++)cin>>grid[i];
        vector<vector<bool>> go(n, vector<bool>(m, false));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='A')go[i][j]=true, ans=1;
            }
        }
        for(int c=0;c<25;c++)
        {
            int cnt = 0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==c+'A'&&go[i][j])
                    {
                        for(int rw=-1;rw<2;rw++)
                        {
                            for(int cl=-1;cl<2;cl++)
                            {
                                int nr=i+rw, nc=j+cl;
                                if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==c+'A'+1)
                                {
                                    cnt++;
                                    go[nr][nc]=true;
                                }
                            }
                        }
                    }
                }
            }
            if(cnt)ans++;
            else break;
        }
        cout << ans << '\n';
    }

    return 0;
}