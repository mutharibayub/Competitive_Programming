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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // initFact();

    vector<bool> canDo(1e6+1, 0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        map<int, int> diffs;
        map<int,int> cnts;
        for(int i=0;i<n;i++)cnts[arr[i]]++;
        int last=-1;
        for(auto [number, count]: cnts)
        {
            if(last!=-1)diffs[number-last]++;
            last=number;
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int idx, newVal;
            cin>>idx>>newVal;
            idx--;

            int toRemove=arr[idx];
            if(--cnts[toRemove]==0)
            {
                auto it = cnts.find(toRemove);
                if(next(it)!=cnts.end())
                {
                    if(--diffs[next(it)->first-toRemove]==0)diffs.erase(next(it)->first-toRemove);
                }
                if(it!=cnts.begin())
                {
                    if(--diffs[toRemove-prev(it)->first]==0)diffs.erase(toRemove-prev(it)->first);
                }
                if(it!=cnts.begin()&&next(it)!=cnts.end())
                {
                    diffs[next(it)->first-prev(it)->first]++;
                }
                cnts.erase(it);
            }
            arr[idx]=newVal;
            if(++cnts[newVal]==1)
            {
                auto it = cnts.find(newVal);
                if(next(it)!=cnts.end())
                {
                    diffs[next(it)->first-newVal]++;
                }
                if(it!=cnts.begin())
                {
                    diffs[newVal-prev(it)->first]++;
                }
                if(next(it)!=cnts.end()&&it!=cnts.begin())
                {
                    if(--diffs[next(it)->first-prev(it)->first]==0)diffs.erase(next(it)->first-prev(it)->first);
                }   
            }
            cout << prev(cnts.end())->first + (diffs.size()?prev(diffs.end())->first:0) << " \n"[i==q-1];
        }
    }
    return 0;
}