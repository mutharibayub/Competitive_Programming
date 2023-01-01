#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 250+1;
const int M = 250+1;
const int inf = 1e9+7;

int dp[N][M][M];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            for(int k=0;k<M;k++)
            {
                dp[i][j][k]=inf;
            }
        }
    }

    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=1;i<n;i++)arr[i]+=arr[i-1];
    dp[0][0][m]=0;
    for(int i=0;i<n;i++) //iterations
    {
        for(int j=0;j<=m;j++) //old sum
        {
            int mn=inf;
            for(int k=m;k>=0;k--) //new val
            {
                mn=min(mn,dp[i][j][k]);
                if(j+k<=m)
                {
                    dp[i+1][j+k][k]=min(dp[i+1][j+k][k], mn+abs(arr[i]-(j+k)));
                }
            }
        }
    }
    int ans=inf;
    for(int i=0;i<=m;i++)ans=min(ans,dp[n][m][i]);
    cout << ans << '\n';

    return 0;
}