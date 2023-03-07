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
        int n;
        cin>>n;
        vector<vector<int>> a(n, vector<int>(n));
        string tmp;
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            for(int j=0;j<n;j++)
            {
                if(tmp[j]-'0')a[i][j]=1;
                else a[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            for(int j=0;j<n;j++)
            {
                if(tmp[j]-'0')a[i][j]^=1;
            }
        }
        bool ok = true;
        for(int r=1;r<n&&ok;r++)
        {
            bool same = (a[r-1][0]==a[r][0]);
            for(int c=1;c<n&&ok;c++)
            {
                if(same != (a[r-1][c]==a[r][c]))ok=false;
            }
        }
        cout << (ok?"YES":"NO") << '\n';
    }

    return 0;
}