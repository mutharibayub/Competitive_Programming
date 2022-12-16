#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <utility>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> arr(n+1);
    vector<array<pair<ll,ll>,8>> dp(n+1);
    for(int i=0;i<8;i++)dp[0][i]={0,0};
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<8;j++)dp[i][j]={0,0};
        for(int j=0;j<8;j++)
        {
            bool has1 = j&(1<<0);
            bool has2 = j&(1<<1);
            bool has3 = j&(1<<2);
            bool add=false;
            if(arr[i]==3)
            {
                if(!has1&&!has2&&!has3)
                {
                    add=true;
                }
                else if(!has3&&has1)
                {
                    has1=false;
                }
                else if(!has3&&has2)
                {
                    has2=false;
                }
                has3=true;
            }
            else if(arr[i]==2)
            {
                if(!has2&&!has3)
                {
                    add=true;
                }
                else if(!has2&&has3)
                {
                    has3=false;
                }
                has2=true;
            }
            else if(arr[i]==1)
            {
                if(!has1&&!has3)
                {
                    add=true;
                }
                else if(!has1&&has3)
                {
                    has3=false;
                }
                has1=true;
            }
            else
            {
                add=true;
            }
            int newMask = (has1<<0)+(has2<<1)+(has3<<2);
            dp[i][newMask].first+=dp[i-1][j].first;
            dp[i][newMask].second+=dp[i-1][j].second+(dp[i-1][j].first*int(add));
            if(!j)
            {
                dp[i][newMask].first++;
                dp[i][newMask].second+=add;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<8;j++)
        {
            ans += dp[i][j].second;
        }
    }
    cout << ans << '\n';


    return 0;
}