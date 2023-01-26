#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

array<int,2> dp[40+1][40+1][40][40];
ll pwr10[40+1][40+1];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<=40;i++)
    {
        for(int j=1;j<=40;j++)
        {
            pwr10[i][j]=i?(pwr10[i-1][j]*10)%j:1;
        }
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        for(int i1=0;i1<=n;i1++)
        {
            for(int i2=0;i2<=n;i2++)
            {
                for(int j=0;j<a;j++)
                {
                    for(int k=0;k<b;k++)
                    {
                        dp[i1][i2][j][k][0]=-1;
                    }
                }
            }
        }
        dp[0][0][0][0][0]=0;
        reverse(s.begin(),s.end());
        for(int i1=0;i1<n;i1++)
        {
            for(int i=0;i<=i1;i++) // red Count
            {
                for(int j=0;j<a;j++) // red mod
                {
                    for(int k=0;k<b;k++) // black mod
                    {
                        if(dp[i1][i][j][k][0]==-1)continue;
                        int redCount = i;
                        int blackCount = i1-i;
                        int redMod = j;
                        int blackMod = k;
                        int num = s[i1]-'0';

                        // make next red
                        int nxtMod = (redMod+num*pwr10[redCount][a]%a)%a;
                        dp[i1+1][redCount+1][nxtMod][blackMod]={0,redMod};

                        // make next black
                        nxtMod = (blackMod+num*pwr10[blackCount][b]%b)%b;
                        dp[i1+1][redCount][redMod][nxtMod]={1,blackMod};
                    }
                }
            }
        }
        int bestRedCount = -1;
        for(int i=1;i<n;i++)
        {
            if(dp[n][i][0][0][0]==-1)continue;
            if(bestRedCount==-1||abs(n/2-bestRedCount)>abs(n/2-i))bestRedCount=i;
        }
        if(bestRedCount==-1)
        {
            cout << -1 << '\n';
            continue;
        }
        int rc = bestRedCount;
        int rm = 0;
        int bm = 0;
        string ans = "";
        for(int i=n;i>0;i--)
        {
            bool isRed = dp[i][rc][rm][bm][0]==0;
            ans.push_back(isRed?'R':'B');
            (isRed?rm:bm) = dp[i][rc][rm][bm][1];
            rc-=isRed;
        }
        cout << ans << '\n';
    }
}