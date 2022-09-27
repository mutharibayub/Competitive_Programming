#include <iostream>
#include <vector>

using namespace std;

int countTexts(string pressedKeys) {
    vector<int64_t> dp(pressedKeys.size()+1, 1);
    for(int i=1;i<=pressedKeys.size();i++)
    {
        dp[i] = dp[i-1];
        for(int j=1;j<=3;j++)
        {
            if(i-j-1<0)break;
            if(pressedKeys[i-1] != pressedKeys[i-j-1])break;
            if(j==3 && pressedKeys[i-1]!='7' && pressedKeys[i-1]!='9')break;
            dp[i] = (dp[i]+dp[i-j-1])%int(1e9+7);
        }
    }
    return dp.back();
}

int main()
{
    countTexts("22233");
    countTexts("222222222222222222222222222222222222");

}