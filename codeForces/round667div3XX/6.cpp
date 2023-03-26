#include <iostream>
#include <vector>

using namespace std;

const int N = 200+1;

int dp[N][N][N];

int main()
{
    int nn, kk;
    cin>>nn>>kk;
    string s, t;
    cin>>s>>t;

    if(t[0]==t[1])
    {
        int count = 0;
        for(int i=0;i<s.size();i++)
        {
            count += s[i]==t[0];
        }
        count = min(nn, count+kk);
        cout << count*(count-1)/2 << '\n';
        return 0;
    }

    for(int i=0;i<=nn;i++)
        for(int j=0;j<=nn;j++)
            for(int k=0;k<=kk;k++)
                dp[i][j][k]=-1;
    
    dp[0][0][kk]=0;

    for(int i=0;i<nn;i++)
        for(int j=0;j<nn;j++)
            for(int k=0;k<=kk;k++)
            {
                if(dp[i][j][k]==-1)continue;
                if(s[i]!=t[0]&&s[i]!=t[1])
                {
                    dp[i+1][j][k]=max(dp[i+1][j][k], dp[i][j][k]); // leave unchanged
                    if(k-1>=0)dp[i+1][j+1][k-1]=max(dp[i+1][j+1][k-1], dp[i][j][k]); // make it t[0]
                    if(k-1>=0)dp[i+1][j][k-1]=max(dp[i+1][j][k-1], dp[i][j][k]+j); // make it t[1]
                }
                else
                {
                    if(k-(s[i]!=t[0])>=0)dp[i+1][j+1][k-(s[i]!=t[0])]=max(dp[i+1][j+1][k-(s[i]!=t[0])], dp[i][j][k]); // make it t[0]
                    if(k-(s[i]!=t[1])>=0)dp[i+1][j][k-(s[i]!=t[1])]=max(dp[i+1][j][k-(s[i]!=t[1])], dp[i][j][k]+j); // make it t[1]
                }
            }

    int ans = 0;
    for(int i=0;i<=nn;i++)
        for(int j=0;j<=kk;j++)
            ans = max(ans, dp[nn][i][j]);
    cout << ans << '\n';

    return 0;
}