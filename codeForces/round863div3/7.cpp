#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

#define tst int tttt;cin>>tttt;while(tttt--)

const int MOD = 1e9+7;
const int N = 5000+1;

ll fact[N];
ll factInv[N];

ll pwr(ll n, ll e)
{
    ll o=1;
    while(e)
    {
        if(e%2)o=(o*n)%MOD;
        n=(n*n)%MOD;
        e/=2;
    }return o;
}

ll getInv(ll n)
{
    return pwr(n, MOD-2);
}

ll nCr(ll n, ll r)
{
    return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
}

inline pair<int,ll> merge(const pair<int,ll> &best1, const pair<int,ll> &best2)
{
    if(best1.first==0&&best2.first==0)return best1;
    if(best1.first>best2.first)return best1;
    if(best2.first>best1.first)return best2;
    return {best1.first, (best1.second+best2.second)%MOD};
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=fact[i-1]*i%MOD;
    factInv[N-1]=getInv(fact[N-1]);
    for(int i=N-2;i>=0;i--)factInv[i]=factInv[i+1]*(i+1)%MOD;

    tst
    {
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i],arr[i]--;

        if(k==1)
        {
            cout << 1 << '\n';
            continue;
        }

        vector<pair<int,ll>> bestCnt(n, {0,1});
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=i-1;j>=0;j--)
            {
                cnt += arr[j]==arr[i];
                if(cnt>=k-1&&arr[j]==arr[i])
                {
                    pair<int, ll> prevBest = j?bestCnt[j-1]:(pair<int,ll>){0,1ll};
                    ll combs = nCr(cnt-1, k-2);
                    prevBest.second=prevBest.second*combs%MOD;
                    prevBest.first++;
                    bestCnt[i]=merge(bestCnt[i], prevBest);
                }
            }
            if(i)bestCnt[i]=merge(bestCnt[i], bestCnt[i-1]);
        }
        cout << bestCnt.back().second << '\n';
    }

    return 0;
}