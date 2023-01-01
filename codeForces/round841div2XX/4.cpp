#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll norm(ll num)
{
    return (num%MOD+MOD)%MOD;
}

ll power(ll n, ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
        {
            ans=norm(ans*n);
        }
        n=norm(n*n);
        e/=2;
    }
    return ans;
}

bool checkGrid(vector<vector<int>> &grid, int l)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        int consec = 0;
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]>=l)
            {
                if(i==0)dp[i][j]=1;
                else dp[i][j]=dp[i-1][j]+1;
            }
            else
            {
                dp[i][j]=0;
            }
            if(dp[i][j]>=l)consec++;
            else consec=0;
            if(consec>=l)return true;
        }
    }
    return false;
}

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
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
            }
        }
        int maxL = min(n,m);
        int ans=1;
        for(int jump=maxL-1;jump;jump/=2)
        {
            while(ans+jump<=maxL&&checkGrid(grid,ans+jump))ans+=jump;
        }
        cout << ans << '\n';
    }

    return 0;
}