#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 100+1;
const int K = 30+1;
int MOD;
ll dp[N][K];
ll fact[N];
ll factInv[N];

ll ncr(ll n, ll r)
{
    return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
}

ll pwr(ll n, ll e)
{
    n%=MOD;
    ll out=1;
    while(e)
    {
        if(e&1)out=(out*n)%MOD;
        n=(n*n)%MOD; 
        e/=2;
    }return out;
}

ll getInv(ll n)
{
    return pwr(n, MOD-2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int nn, kk;
    cin>>nn>>kk>>MOD;

    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%MOD;
    factInv[N-1]=getInv(fact[N-1]);
    for(int i=N-2;i>=0;i--)factInv[i]=factInv[i+1]*(i+1)%MOD;

    ll ans = 0;

    for(int i=0;i<kk;i++) //ignore this num
    {
        for(int j=0;j<nn;j++)
        {
            for(int k=0;k<kk;k++)
            {
                dp[j][k]=0;
            }
        }
        dp[0][0]=1;
        for(int j=0;j<nn-1;j++) // digitNum
        {
            for(int k=0;k<kk;k++) // to add
            {
                if(k==i)continue;
                for(int l=0;l<kk;l++) // add to this
                {
                    dp[j+1][(l+k)%kk]=(dp[j+1][(l+k)%kk]+dp[j][l])%MOD;
                }
            }
        }
        for(int j=1;j<=nn;j++)
        {
            ans = (ans+ncr(nn, j)*dp[nn-j][i]%MOD)%MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}