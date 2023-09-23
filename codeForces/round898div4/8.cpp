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

// const int N = 1e5+1;
// const int MOD = 998244353;
// // ll fact[N];
// // ll factInv[N];
// // ll nCr(ll n, ll r)
// // {
// //     return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
// // }
// // ll pwr(ll b, ll e)
// // {
// //     ll o=1;
// //     while(e)
// //     {
// //         if(e&1)o=(o*b)%MOD;
// //         b=(b*b)%MOD;
// //         e/=2;
// //     }return o;
// // }
// // ll getInv(ll n)
// // {
// //     return pwr(n, MOD-2);
// // }
// // void initFact()
// // {
// //     fact[0]=1;
// //     for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%MOD;
// //     factInv[N-1]=getInv(fact[N-1]);
// //     for(int i=N-2;i>=0;i--)factInv[i]=(factInv[i+1]*(i+1))%MOD;
// // }

int getParent(vector<int> &parent, int u)
{
    if(parent[parent[u]]!=parent[u])
    {
        parent[u]=getParent(parent, parent[u]);
    }return parent[u];
}

bool dfs(vector<vector<int>> &al, vector<bool> &inCycle, vector<bool> &inArm, vector<bool> &vis, vector<int> &arm, int u)
{
    inArm[u]=true;
    arm.push_back(u);
    vis[u]=true;
    for(auto v: al[u])
    {
        if(arm.size()>=2&&!(arm[arm.size()-2]==v)&&inArm[v])
        {
            for(int i=arm.size()-1;i>=0;i--)
            {
                inCycle[arm[i]]=true;
                if(arm[i]==v)break;
            }
            return true;
        }
        else if(!vis[v])
        {
            if(dfs(al, inCycle, inArm, vis, arm, v))
                return true;
        }
    }
    inArm[u]=false;
    arm.pop_back();
    return false;
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
        int n, a, b;
        cin>>n>>a>>b;
        a--, b--;
        vector<vector<int>> al(n);
        for(int i=0;i<n;i++)
        {
            int u, v;
            cin>>u>>v;
            u--, v--;
            al[u].push_back(v);
            al[v].push_back(u);
        }

        vector<bool> inCycle(n, 0);
        vector<bool> inArm(n, 0);
        vector<bool> vis(n, 0);
        vector<int> arm;
        assert(dfs(al, inCycle, inArm, vis, arm, 0));

        vector<int> dist(n, 1e9);
        queue<int> q;
        
        int ans = -1;
        for(int i=0;i<n&&ans==-1;i++)
        {
            if(!inCycle[i])
                continue;
            bool foundA = false, foundB = false;
            q.push(i);
            dist[i]=0;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                foundA |= (u==a);
                foundB |= (u==b);
                for(auto v: al[u])
                {
                    if(dist[v]!=1e9 || inCycle[v])
                        continue;
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
            if(foundA && foundB)
            {
                ans = (dist[a] > dist[b]);
            }
        }

        if (ans == -1)
        {
            for(int i=0;i<n;i++)
                dist[i]=1e9;

            q.push(b);
            dist[b]=0;
            int aToB = 1e9;
            int bToCycle = inCycle[b]?0:1e9;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                if(u==a && aToB == 1e9)
                    aToB = dist[u];
                if(inCycle[u] && bToCycle == 1e9)
                    bToCycle = dist[u];
                for(auto v:al[u])
                {
                    if(dist[v]!=1e9)
                        continue;
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
            ans = (bToCycle < aToB-bToCycle);
        }

        assert(ans!=-1);
        cout << (ans?"YES":"NO") << '\n';

    }
    return 0;
}