#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

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
        int pow10=1;
        vector<string> dp(n, string());
        vector<int> prv = {0};
        int mxLen = 0;
        bool found=false;
        while(1)
        {
            vector<int> toAdd;
            for(auto ele:prv)
            {
                if(dp[(ele+pow10)%n].empty() || (ele+pow10)%n == 0)
                {
                    dp[(ele+pow10)%n]=dp[ele]+"1";
                    toAdd.push_back((ele+pow10)%n);
                    if((ele+pow10)%n==0)
                    {
                        found=true;
                        break;
                    }
                }
                dp[ele].push_back('0');
            }
            prv.insert(prv.end(), toAdd.begin(), toAdd.end());
            if(found)break;
            pow10=(pow10*10)%n;
        }
        while(dp[0].back()=='0')dp[0].pop_back();
        reverse(dp[0].begin(), dp[0].end());
        cout << dp[0] << '\n';
    }
    return 0;
}