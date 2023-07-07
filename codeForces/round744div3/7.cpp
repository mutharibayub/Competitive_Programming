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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<int> dp(1000+1,1e9+7);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            vector<int> nxt(1000+1,1e9+7);
            for(int j=0;j<1000+1;j++)
            {
                if(dp[j]==1e9+7)continue;
                int edgeDist = j;
                int len = dp[j];
                int nextLen,nextEdgeDist;
                nextEdgeDist=j-arr[i];
                nextLen=len;
                if(nextEdgeDist<0)
                {
                    nextLen=len+(-1*nextEdgeDist);
                    nextEdgeDist=0;
                }
                if(nextEdgeDist>nextLen/2)nextEdgeDist=nextLen-nextEdgeDist;
                if(nextEdgeDist<=1000)nxt[nextEdgeDist]=min(nxt[nextEdgeDist],nextLen);
                nextEdgeDist=j+arr[i];
                nextLen=len;
                if(nextEdgeDist>=len)
                {
                    nextLen=len+(nextEdgeDist-len);
                    nextEdgeDist=0;
                }
                if(nextEdgeDist>nextLen/2)nextEdgeDist=nextLen-nextEdgeDist;
                if(nextEdgeDist<=1000)nxt[nextEdgeDist]=min(nxt[nextEdgeDist],nextLen);            
            }
            dp=nxt;
        }
        int ans = 1e9+7;
        for(int i=0;i<=1000;i++)
        {
            ans=min(ans,dp[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}