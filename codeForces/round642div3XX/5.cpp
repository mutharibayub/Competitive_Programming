#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> sm(n);
        vector<int> dp(n);
        sm[0]=s[0]=='1';
        for(int i=1;i<n;i++)sm[i]=sm[i-1]+(s[i]=='1');
        int ans = sm.back();
        for(int i=0;i<n;i++)
        {
            int prev = i-k;
            dp[i]=(i?sm[i-1]:0)+(s[i]=='0');
            if(prev>=0)dp[i]=min(dp[i], dp[prev]+sm[i-1]-sm[prev]+(s[i]=='0'));
            ans = min(ans, dp[i]+sm.back()-sm[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}