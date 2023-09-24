#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

class FenwickTree
{
    vector<int> arr;
public:
    FenwickTree(int n)
    {
        arr.resize(n+1, 0);
    }
    int get(int idx)
    {
        idx++;
        int o=0;
        while(idx)
        {
            o+=arr[idx];
            idx-=idx&-idx;
        }return o;
    }
    void update(int idx, int update)
    {
        idx++;
        while(idx<arr.size())
        {
            arr[idx]+=update;
            idx+=idx&-idx;
        }
    }
};

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

const int N = 1000+1;
const int MOD = 1e9+7;
ll fact[N];
ll factInv[N];
ll nCr(ll n, ll r)
{
    return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
}
ll pwr(ll b, ll e)
{
    ll o=1;
    while(e)
    {
        if(e&1)o=(o*b)%MOD;
        b=(b*b)%MOD;
        e/=2;
    }return o;
}
ll getInv(ll n)
{
    return pwr(n, MOD-2);
}
void initFact()
{
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%MOD;
    factInv[N-1]=getInv(fact[N-1]);
    for(int i=N-2;i>=0;i--)factInv[i]=(factInv[i+1]*(i+1))%MOD;
}

void dfs(int u, vector<vector<int>> &al, vector<int> &parent, vector<int> &count)
{
    count[u]=1;
    for(auto v:al[u])
    {
        if(parent[u]==v)continue;
        parent[v]=u;
        dfs(v, al, parent, count);
        count[u]+=count[v];
    }
}

const int MAXN = 1e6+1;

template<int len = 1>
int subsetSum(vector<int> &cnts, int sm)
{
    if(len < sm/2+1)
    {
        return subsetSum<min(MAXN, len*2)>(cnts, sm);
    }

    bitset<len> dp;
    
    dp[0] = 1;
    for(int i=0;i<cnts.size();i++)
    {
        for(int j=0;j<cnts[i];j++)
        {
            dp=dp|(dp<<i);
        }
    }

    int val = -1;
    for(int i=sm/2;i>=0;i--)
    {
        if(dp[i])
        {
            val=i;
            break;
        }
    }
    return val;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // initFact();

    int tttt=1;
    // cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<vector<int>> al(n);
        vector<int> parent(n, -1);
        for(int i=1;i<n;i++)
        {
            int u;
            cin>>u;
            u--;
            al[u].push_back(i);
            al[i].push_back(u);
        }
        vector<int> count(n);
        dfs(0, al, parent, count);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int> nums;
            int sm=0;
            int mx=0;
            for(auto ele:al[i])
            {
                if(parent[i]==ele)continue;
                nums.push_back(count[ele]);
                mx=max(mx, count[ele]);
                sm+=count[ele];
            }
            if(nums.size()>1)
            { 
                if(mx>=sm/2)
                {
                    ans += 1ll*mx*(sm-mx);
                }
                else
                {
                    vector<int> cnts(sm/2+1, 0);
                    for(auto num: nums)
                        cnts[num]++;
                    for(int cntOf=0;cntOf<=sm/2;cntOf++)
                    {
                        if(!cnts[cntOf])
                            continue;
                        int transfer = max(cnts[cntOf]-1, 0) / 2;
                        cnts[cntOf]-=2*transfer;
                        if(cntOf*2<=sm/2)
                            cnts[cntOf*2]+=transfer;
                    }
                    int val = subsetSum(cnts, sm);
                    ans += 1ll*val*(sm-val);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}