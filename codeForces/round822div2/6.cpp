#include <iostream>
#include <vector>
#include <array>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        m--;
        ll dp[2][2][2];
        ll nxt[2][2][2];
        for(int i=0;i<8;i++)
        {
            dp[i&1][bool(i&2)][bool(i&4)]=0;
        }
        dp[0][0][0]=1;
        for(int i=62;i>=0;i--)
        {
            for(int j=0;j<8;j++)
            {
                nxt[j&1][bool(j&2)][bool(j&4)]=0;
            }
            // if(i==0)
            // {
            //     cout << "YO" << '\n';
            // }
            for(int par=0;par<2;par++)
            {
                for(int under=0;under<2;under++)
                {
                    for(int ld=0;ld<2;ld++)
                    {
                        for(int bit=0;bit<2;bit++)
                        {
                            if(!under&&bit>bool(m&(1ll<<i)))continue;
                            bool nunder=under||(!under&&bit<bool(m&(1ll<<i)));
                            int nld=(bit?ld+1:0)%2; // next leading digits
                            int npar=(par+2*bit)%2; // next parity
                            if((n&(1ll<<i)))
                            {
                                npar=abs(npar-nld+1)%2;
                                nld=!bit&&!ld;
                            }
                            nxt[npar][nunder][nld]+=dp[par][under][ld];
                        }
                    }
                }
            }
            for(int j=0;j<8;j++)
            {
                dp[j&1][bool(j&2)][bool(j&4)]=nxt[j&1][bool(j&2)][bool(j&4)];
            }
        }
        ll ans=0;
        for(int i=0;i<4;i++)
        {
            ans+=dp[1][i&1][bool(i&2)];
        }
        cout << ans << '\n';
    }

    return 0;
}