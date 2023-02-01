#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
const int N = 200+1;

ll fact[N];
ll pow2[N];
ll factInv[N];

ll pwr(ll n, ll e, ll mod=MOD)
{
    ll ans=1;
    n%=mod;
    while(e)
    {
        if(e&1)
        {
            ans=(ans*n)%mod;
        }
        n=(n*n)%mod;
        e/=2;
    }
    return ans;
}

ll getInv(ll n)
{
    return pwr(n, MOD-2);
}

ll nCr(ll n, ll r)
{
    return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
}

void countArm(vector<vector<int>> &al, vector<vector<int>> &count, int node)
{
    int n=al.size();
    queue<array<int,2>> q;
    vector<bool> done(n, false);
    done[node]=true;
    for(int i=0;i<al[node].size();i++)
    {
        q.push({al[node][i],1});
        done[al[node][i]]=true;
        int cnt=0;
        int dist=1;
        while(!q.empty())
        {
            int top = q.front()[0];
            int topDist = q.front()[1];
            q.pop();
            if(topDist>dist)
            {
                count[dist].push_back(cnt);
                dist++;
                cnt=0;
            }
            cnt++;
            for(auto neigh:al[top])
            {
                if(!done[neigh])
                {
                    q.push({neigh, topDist+1});
                    done[neigh]=true;
                }
            }
        }
        if(cnt)count[dist].push_back(cnt);
    }
}

ll getCount(vector<vector<int>> &count, int k)
{
    ll cnt=0;
    for(int i=0;i<count.size();i++)
    {
        if(count[i].size()<k)continue;
        vector<ll> dp(k+1, 0);
        for(int j=0;j<count[i].size();j++)
        {
            for(int i1=k-1;i1>=0;i1--)
            {
                dp[i1+1]=(dp[i1+1]+dp[i1]*count[i][j])%MOD;
            }
            dp[1]=(dp[1]+count[i][j])%MOD;
        }
        cnt=(cnt+dp[k])%MOD;
    }
    return cnt;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pow2[0]=1;
    for(int i=1;i<N;i++)pow2[i]=pow2[i-1]*2%MOD;
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=fact[i-1]*i%MOD;
    factInv[N-1]=getInv(fact[N-1]);
    for(int i=N-2;i>=0;i--)factInv[i]=factInv[i+1]*(i+1)%MOD;

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<vector<int>> al(n);
        vector<vector<vector<int>>> armCount(n, vector<vector<int>>(n+1));
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            al[u].push_back(v);
            al[v].push_back(u);
        }

        if(k==2)
        {
            cout << nCr(n, 2) << '\n';
            continue;
        }

        for(int i=0;i<n;i++)
        {
            countArm(al, armCount[i], i);
        }

        ll ans = 0;
        for(int i=0;i<n;i++)
        {
            ans=(ans+getCount(armCount[i], k))%MOD;
        }

        cout << ans << '\n';

    }

    return 0;
}