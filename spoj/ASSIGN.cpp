#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll getBest(vector<ll> &dp, vector<int> &grid, int mask, int row)
{
    if(dp[mask]==-1)
    {
        ll val = 0;
        if(row==grid.size())return 1;
        for(int col=0;col<grid.size();col++)
        {
            if(mask&(1<<col))continue;
            if(grid[row]&(1<<col))
            {
                val+=getBest(dp, grid, mask|(1<<col), row+1);
            }
        }
        dp[mask]=val;
    }
    return dp[mask];
}

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
        vector<int> grid(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int tmp;
                cin>>tmp;
                if(tmp)
                {
                    grid[i]|=(1<<j);
                }
            }
        }
        vector<ll> dp((1<<n), -1);
        cout << getBest(dp, grid, 0, 0) << '\n';
    }

    return 0;
}