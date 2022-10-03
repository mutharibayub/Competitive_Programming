#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> mat(n, vector<int>(n,-1));
    for(int i=0;i<n;i++)
    {
        cin>>mat[i][i];
    }
    for(int diag=1;diag<n;diag++)
    {
        for(int i=diag;i<n;i++)
        {
            int j = i-diag;
            if(mat[i-1][j+1]==-1)
            {
                mat[i][j]=0;
            }
            else
            {
                int crossMode = (mat[i-1][j]+mat[i][j+1])%n;
                mat[i][j] = (crossMode-mat[i-1][j+1]+1+n)%n;
            }
        }
        for(int i=0;i+diag<n;i++)
        {
            int j = i+diag;
            if(mat[i+1][j-1]==-1)
            {
                mat[i][j]=0;
            }
            else
            {
                int crossMode = (mat[i+1][j]+mat[i][j-1])%n;
                mat[i][j] = (crossMode-mat[i+1][j-1]+1+n)%n;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j)cout << ' ';
            cout << mat[i][j];
        }
        cout << '\n';
    }

    return 0;
}