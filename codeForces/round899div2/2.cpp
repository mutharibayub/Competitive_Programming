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
#include <limits>

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

// const int N = 2e5+1;
// const int MOD = 998244353;
// ll fact[N];
// ll factInv[N];
// ll nCr(ll n, ll r)
// {
//     return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
// }
// ll pwr(ll b, ll e)
// {
//     ll o=1;
//     while(e)
//     {
//         if(e&1)o=(o*b)%MOD;
//         b=(b*b)%MOD;
//         e/=2;
//     }return o;
// }
// ll getInv(ll n)
// {
//     return pwr(n, MOD-2);
// }
// void initFact()
// {
//     fact[0]=1;
//     for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%MOD;
//     factInv[N-1]=getInv(fact[N-1]);
//     for(int i=N-2;i>=0;i--)factInv[i]=(factInv[i+1]*(i+1))%MOD;
// }

int getParent(vector<int> &parent, int u)
{
    if(parent[parent[u]]!=parent[u])
    {
        parent[u]=getParent(parent, parent[u]);
    }return parent[u];
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // initFact();

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        array<bool, 50> allSet = {0};
        vector<array<bool, 50>> sets(n, {0});
        for(int i=0;i<n;i++)
        {
            int k;
            cin>>k;
            for(int j=0;j<k;j++)
            {
                int tmp;
                cin>>tmp;
                sets[i][tmp-1]=1;
                allSet[tmp-1]=1;
            }
        }
        int ans=0;
        for(int i=0;i<50;i++)
        {
            if(!allSet[i])
                continue;
            array<bool, 50> curSet = {0};
            for(int j=0;j<n;j++)
            {
                if(sets[j][i])
                    continue;
                for(int k=0;k<50;k++)
                {
                    if(sets[j][k])
                        curSet[k]=1;
                }
            }
            int cnt=0;
            for(int j=0;j<50;j++)
            {
                cnt+=curSet[j];
            }
            ans=max(ans, cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}