#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(const int &l, const int &r)
{
    return (l&1)<(r&1) || (((l&1)==(r&1)) && (l<=r));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int64_t n,x,y;
        cin>>n>>x>>y;
        string bin1,bin2;
        cin>>bin1>>bin2;
        vector<int64_t> diff;
        for(int i=0;i<n;i++)
        {
            if(bin1[i]!=bin2[i])
            {
                diff.push_back(i);
            }
        }
        if(diff.size()&1)
        {
            cout << "-1\n";
            continue;
        }
        if(diff.size()==0)
        {
            cout << "0\n";
            continue;
        }
        auto getMin = [diff,x,y](int l, int r)
        {
            return min((diff[r]-diff[l])*x, abs(diff[r]-diff[l])==1?2*y:y);
        };
        vector<vector<int64_t>> dp(diff.size(), vector<int64_t>(diff.size(),0));
        for(int i=0;i<diff.size()-1;i++)
        {
            dp[i][i+1] = getMin(i,i+1);
        }
        for(int i=4;i<=diff.size();i+=2)
        {
            for(int j=0;i+j<=diff.size();j++)
            {
                dp[j][j+i-1] = min(getMin(j+i-2,j+i-1)+dp[j][j+i-3],
                                    min(
                                        min(getMin(j,j+1)+dp[j+2][j+i-1],
                                            getMin(j,j+i-1)+dp[j+1][j+i-2]),
                                        (i/2)*y
                                    ));
                // cout << "i: " << i << " j: " << j << " j+i-1: " << j+i-1 << " dp = " << dp[j][j+i-1] << '\n';
            }
        }
        cout << dp[0][diff.size()-1] << '\n';
    }

    return 0;
}