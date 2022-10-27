#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <assert.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    vector<string> mat(n);
    int colStart = 0;
    vector<int> rowCounts(n,0);
    vector<int> colCounts(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>mat[i];
        for(int j=0;mat[i][j];j++)
        {
            rowCounts[i]+=(mat[i][j]=='1');
            colCounts[j]+=(mat[i][j]=='1');
        }
    }
    
    for(int i=0;i<q;i++)
    {
        int qt;
        cin>>qt;
        if(qt==1)
        {
            int y,x,v;
            cin>>y>>x>>v;
            y--,x--;
            v+='0';
            x = (colStart+x)%n;
            if(mat[y][x]=='1')
            {
                colCounts[x]--;
                rowCounts[y]--;
            }
            mat[y][x] = v;
            if(mat[y][x]=='1')
            {
                colCounts[x]++;
                rowCounts[y]++;
            }            
        }
        else
        {
            int v;
            cin>>v;
            v+='0';
            colStart = (colStart+n-1)%n;
            if(v!=mat[n-1][colStart])colCounts[colStart]+=(v=='1'?1:-1);
            for(int i=0;i<n;i++)
            {
                int tmp = mat[i][colStart];
                if(mat[i][colStart]=='1')
                {
                    rowCounts[i]--;
                }
                mat[i][colStart] = v;
                if(mat[i][colStart]=='1')
                {
                    rowCounts[i]++;
                }
                v = tmp;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans += colCounts[i]==n;
            ans += rowCounts[i]==n;
        }
        cout << ans << '\n';
    }

    return 0;
}