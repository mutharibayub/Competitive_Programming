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
const int MOD = 998244353;
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

int getParent(vector<int> &parent, int u)
{
    if(parent[parent[u]]!=parent[u])
    {
        parent[u]=getParent(parent, parent[u]);
    }return parent[u];
}

void findBest(vector<array<int, 4>> &segs, set<pair<int, int>> &start, set<pair<int, int>> &end,
            vector<pair<pair<int, int>, int>> &bestPoss, int l, int r, int best)
{
    vector<int> goodSegments;
    auto it = start.lower_bound({l, 0});
    for(;it!=start.end();it++)
    {
        int segment = it->second;
        if(it->first>r)break;
        goodSegments.push_back(segment);
    }
    it = end.lower_bound({l, 0});
    for(;it!=end.end();it++)
    {
        int segment = it->second;
        if(it->first>r)break;
        goodSegments.push_back(segment);
    }
    vector<array<int, 3>> inps;
    for(auto segment: goodSegments)
    {
        if(start.find({segs[segment][2], segment})==start.end())continue;
        start.erase({segs[segment][2], segment});
        end.erase({segs[segment][3], segment});

        bestPoss.push_back({{segs[segment][0], segs[segment][1]}, best});
        
        inps.push_back({segs[segment][0], segs[segment][1], best});  
    }
    for(auto inp: inps)
    {
        findBest(segs, start, end, bestPoss, inp[0], inp[1], inp[2]); 
    }
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
        vector<array<int, 4>> segs(n);
        set<pair<int, int>> start, end;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<4;j++)cin>>segs[i][j];
            start.emplace(segs[i][2], i);
            end.emplace(segs[i][3], i);
        }
        vector<pair<pair<int, int>, int>> bestPoss;
        while(!end.empty())
        {
            int segment = prev(end.end())->second;
            end.erase(--end.end());
            start.erase({segs[segment][2], segment});

            bestPoss.push_back({{segs[segment][0], segs[segment][1]}, segs[segment][3]});

            findBest(segs, start, end, bestPoss, segs[segment][0], segs[segment][1], segs[segment][3]);
        }
        map<int, vector<int>> checkpoints;
        for(int i=0;i<bestPoss.size();i++)
        {
            checkpoints[bestPoss[i].first.first].push_back(bestPoss[i].second);
            checkpoints[bestPoss[i].first.second+1].push_back(-bestPoss[i].second);
        }
        vector<pair<int, pair<int, int>>> rngs;
        int cur=-1;
        int last=-1;
        map<int, int> state;
        for(auto [loc, points]: checkpoints)
        {
            for(auto point: points)
            {
                if(point<0)
                {
                    if(!--state[-point])
                        state.erase(-point);
                }
                else
                {
                    state[point]++;
                }
            }
            int maxState = state.size()?prev(state.end())->first:-1;
            if(cur!=maxState)
            {
                if(cur!=-1)rngs.push_back({last,{loc-1, cur}});
                if(maxState!=-1)last=loc;
                cur=maxState;
            }
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int x;
            cin>>x;
            auto it = lower_bound(rngs.begin(), rngs.end(), make_pair(x+1, make_pair(0, 0)));
            int bestMove = 0;
            if(it!=rngs.begin()&&prev(it)->second.first>=x)bestMove = prev(it)->second.second;
            cout << max(x, bestMove) << " \n"[i==q-1];
        }        
    }
    return 0;
}