#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int sum;
    int score;
};

int main()
{
    int n;
    cin>>n;
    vector<vector<node>> dp(n, vector<node>(n));
    for(int i=0;i<n;i++)
    {
        cin>>dp[i][i].sum;
        dp[i][i].score = dp[i][i].sum;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;i+j<n;j++)
        {
            dp[j][i+j].sum = dp[j][i+j-1].sum + dp[i+j][i+j].sum;
            dp[j][i+j].score = max(dp[j][i+j-1].score+dp[j][i+j-1].sum+dp[i+j][i+j].sum,
                                    dp[j][j].sum+dp[j+1][i+j].sum+dp[j+1][i+j].score);
        }
    }
    cout << dp[0][n-1].score << endl;
    return 0;
}