#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs(const string &s1, const string &s2)
{
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
        }
    }
    return dp.back().back();
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s,rs;
        cin>>s;
        rs = s;
        reverse(rs.begin(), rs.end());
        int lcsLen = lcs(s, rs);
        cout << s.size() - lcsLen <<'\n';
    }


    return 0;
}