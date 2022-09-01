#include <iostream>
#include <vector>

using namespace std;

void testCase()
{
    string a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
    for(int i=0;i<dp.size();i++)
    {
        dp[i][0] = i;
    }
    for(int i=0;i<dp[0].size();i++)
    {
        dp[0][i] = i;
    }
    for(int i=1;i<dp.size();i++)
    {
        for(int j=1;j<dp[0].size();j++)
        {
            if(a[i-1] == b[j-1])
            {
                dp[i][j] = min(dp[i-1][j-1]-1, min(dp[i-1][j], dp[i][j-1])) + 1;       
            }
            else
            {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;  
            }
        }
    }
    cout<<dp.back().back()<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        testCase();
    }

}