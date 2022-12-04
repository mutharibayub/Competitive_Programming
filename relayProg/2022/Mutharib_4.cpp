#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int i=0;i+2<n;i++)
    {
        for(int j=0;j+2<m;j++)
        {
            int tmp=0;
            for(int a=0;a<3;a++)
            {
                for(int b=0;b<3;b++)
                {
                    tmp+=mat[i+a][j+b];
                }
            }
            tmp-=mat[i+1][j];
            tmp-=mat[i+1][j+2];
            ans=max(ans, tmp);
        }
    }
    cout << ans << '\n';
    return 0;
}