#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int R,C,K;
    cin>>R>>C>>K;
    K++;

    vector<vector<string>> grids(K, vector<string>(R));
    for(int i=0;i<K;i++)
    {
        for(int j=0;j<R;j++)
        {
            cin>>grids[i][j];
        }
    }

    vector<pair<int,int>> ord(K);
    for(int k=0;k<K;k++)
    {
        auto &grid = grids[k];
        int cnt=0;
        for(int i=1;i+1<R;i++)
        {
            for(int j=1;j+1<C;j++)
            {
                int sur = 1ll*grid[i-1][j]+grid[i+1][j]+grid[i][j-1]+grid[i][j+1]-4*'0';
                if((sur==0&&grid[i][j]=='1')||(sur==4&&grid[i][j]=='0'))
                {
                    cnt++;
                }
            }
        }
        ord[k]=make_pair(cnt,k);
    }
    sort(ord.rbegin(), ord.rend());
    int first = ord[0].second;
    cout << first + 1 << '\n';
    vector<string> ans;
    for(int k=0;k+1<K;k++)
    {
        int idx = ord[k+1].second;
        for(int i=1;i+1<R;i++)
        {
            for(int j=1;j+1<C;j++)
            {
                if(grids[first][i][j]!=grids[idx][i][j])
                {
                    ans.push_back("1 "+to_string(i+1)+" "+to_string(j+1));
                    grids[first][i][j]=((grids[first][i][j]-'0')^1)+'0';
                }
            }
        }
        ans.push_back("2 "+to_string(idx+1));
    }
    cout << ans.size() << '\n';
    for(auto q:ans)
    {
        cout << q << '\n';
    }
    return 0;
}