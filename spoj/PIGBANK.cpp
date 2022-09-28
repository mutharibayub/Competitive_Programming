#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int tmp,w;
        cin>>tmp>>w;
        w-=tmp;
        int n;
        cin>>n;
        vector<array<int,2>> curr(n);
        vector<int> dp(w+1,1e9+7);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            cin>>curr[i][0]>>curr[i][1];
        }
        for(int i=1;i<=w;i++)
        {
            for(auto cur:curr)
            {
                if(i-cur[1]>=0)
                {
                    dp[i] = min(dp[i], dp[i-cur[1]]+cur[0]);
                }
            }
        }if(dp.back()==int(1e9+7))
        {
            cout << "This is impossible.\n";
        }
        else
        {
            cout << "The minimum amount of money in the piggy-bank is " << dp.back() << ".\n";

        }
    }


    return 0;
}