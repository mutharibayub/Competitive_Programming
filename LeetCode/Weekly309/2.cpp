#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        endPos += 500;
        startPos += 500;
        vector<vector<int64_t>> dp(k+1, vector<int64_t>(2000+1,0));
        dp[0][endPos] = 1;
        for(int steps=1;steps<=k;steps++)
        {
            for(int i=0;i<=2000;i++)
            {
                if(i)
                {
                    dp[steps][i] = (dp[steps][i]+dp[steps-1][i-1])%int(1e9+7);
                }
                if(i+1<dp[0].size())
                {
                    dp[steps][i] = (dp[steps][i]+dp[steps-1][i+1])%int(1e9+7);
                }
            }
        }
        return dp[k][startPos];        
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    cout << s.numberOfWays(272,270,6);

    return 0;
}