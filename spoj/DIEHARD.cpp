#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> dp(2000+1, vector<int>(2000+1,0));
    for(int h=0;h<=2000;h++)
    {
        for(int a=0;a<=2000;a++)
        {
            int w=0,f=0;
            if(h-5>0 && a-10>0)
            {
                w=dp[h-2][a-8]+2;
            }
            if(h-20>0)
            {
                f=dp[h-17][a+7]+2;
            }            
            dp[h][a] = max(w,f);
        }
    }
    
    // for(int i=0;i<=20;i++)
    // {
    //     for(int j=0;j<=20;j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // return 0;
    int t;
    cin>>t;
    while(t--)
    {
        int h,a;
        cin>>h>>a;
        h+=3,a+=2;
        cout << dp[h][a]+1 << '\n';
    }

    return 0;
}
