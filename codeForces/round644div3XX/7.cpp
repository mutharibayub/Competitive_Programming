#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n, m, a, b;
        cin>>n>>m>>a>>b;
        if(n*a!=m*b)
        {
            cout << "NO" << '\n';
        }
        else 
        {
            vector<vector<int>> mat(n, vector<int>(m,0));
            int col = 0, row = 0;
            for(int i=0;i<n*a;i++)
            {
                mat[row][col%m]=1;
                if(++col%a==0)row++;
            }

            cout << "YES" << '\n';
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout << mat[i][j];
                }cout << '\n';
            }
        }
    }
    return 0;
}