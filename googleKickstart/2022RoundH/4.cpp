#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long ll;

const int N = 1e5+1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            arr[i]--;
        }
        vector<int> cycleCount(n+1,0);
        vector<bool> done(n, false);
        vector<int> dp(n+1, 1e9+7);
        
        for(int i=0;i<n;i++)
        {
            int n=arr[i];
            int len=0;
            while(!done[n])
            {
                done[n]=true;
                n = arr[n];
                len++;
            }
            if(len)cycleCount[len]++;
        }

        dp[0]=-1;
        vector<int> tmp;
        for(int i=1;i<=n;i++)
        {
            if(!cycleCount[i])continue;
            tmp=dp;
            int len = i;
            for(int j=0;j<len;j++)
            {
                deque<int> dq;
                for(int l=j;l<=n;l+=len)
                {
                    if((bool)dq.size())
                    {
                        dp[l]=min(tmp[l], tmp[dq.front()]+(l-dq.front())/len);
                    }
                    while((bool)dq.size() && (l-dq.front())/len>=cycleCount[len])
                    {
                        dq.pop_front();
                    }
                    while((bool)dq.size() && tmp[dq.back()]>tmp[l])
                    {
                        dq.pop_back();
                    }
                    dq.push_back(l);
                }
            }
        }

        int minVal = 1e9+7;
        for(int i=n;i>=1;i--)
        {
            dp[i] = min(dp[i], minVal+1);
            minVal = min(minVal, dp[i]);
        }

        cout << "Case #" << t << ":";
        for(int i=1;i<=n;i++)
        {
            cout << ' ' << dp[i];
        }
        cout << '\n';
    }   


    return 0;
}