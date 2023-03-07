#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

const int N = 2e5+1;

vector<int> mults[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<N;i++)mults[i].clear();

        int n;
        cin>>n;
        vector<int> cnts(N, 0);
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            cnts[tmp]++;
        }
        for(int i=1;i<N;i++)
        {
            if(cnts[i]==0)continue;
            for(int j=2;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    mults[j].push_back(i);
                    if(j*j!=i)mults[i/j].push_back(i);
                }
            }
            if(i!=1)mults[1].push_back(i);
        }
        int ans = 0;
        vector<int> dp(N, 0);
        for(int i=N-1;i>0;i--)
        {
            if(cnts[i]==0)continue;
            for(auto mul:mults[i])
            {
                dp[i]=max(dp[i], dp[mul]);
            }
            dp[i]+=cnts[i];
            ans = max(ans, dp[i]);
        }
        cout << n-ans << '\n';
    }

    return 0;
}