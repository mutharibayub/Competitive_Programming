#include <iostream>
#include <vector>
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
        int n,m;
        cin>>n>>m;
        vector<string> mat(n);
        vector<vector<int>> ans(n, vector<int>(m,9999));
        for(int i=0;i<n;i++)
        {
            cin >> mat[i];
        }
        queue<array<int,3>> q;
        vector<vector<bool>> done(n, vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='1')
                {
                    q.push({i,j,0});
                    done[i][j] = true;

                }
            }
        }
        while(!q.empty())
        {
            array<int,3> tmp = q.front();
            q.pop();
            ans[tmp[0]][tmp[1]]=tmp[2];
            if(tmp[0]-1>=0 && !done[tmp[0]-1][tmp[1]])
            {
                q.push({tmp[0]-1,tmp[1],tmp[2]+1});
                done[tmp[0]-1][tmp[1]] = true;
            }
            if(tmp[1]-1>=0 && !done[tmp[0]][tmp[1]-1])
            {
                q.push({tmp[0],tmp[1]-1,tmp[2]+1});
                done[tmp[0]][tmp[1]-1] = true;
            }
            if(tmp[0]+1<n && !done[tmp[0]+1][tmp[1]])
            {
                q.push({tmp[0]+1,tmp[1],tmp[2]+1});
                done[tmp[0]+1][tmp[1]] = true;
            }
            if(tmp[1]+1<m && !done[tmp[0]][tmp[1]+1])
            {
                q.push({tmp[0],tmp[1]+1,tmp[2]+1});
                done[tmp[0]][tmp[1]+1] = true;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<ans[i][j];
                if(j+1<m)cout<<' ';
            }
            cout<<'\n';
        }
    }

    return 0;
}