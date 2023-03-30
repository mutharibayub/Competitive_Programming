#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mm(m, vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mm[j][i];
            }
        }
        for(int i=0;i<m;i++)
        {
            sort(mm[i].begin(), mm[i].end());
        }
        ll ans = 0;
        for(int i=0;i<m;i++)
        {
            ll sum = 0;
            for(int j=0;j<n;j++)
            {
                ans += sum;
                if(j<n)sum+=1ll*(j+1)*(mm[i][j+1]-mm[i][j]); 
            }
        }
        cout << ans << '\n';
    }
    return 0;
}