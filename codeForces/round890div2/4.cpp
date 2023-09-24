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

        set<int> peaks;
        
        bool big = true;
        for(int i=0;i<n-1;i++)
        {
            cout << "? " << i+1 << " " << i+2 << endl;
            int tmp;
            cin>>tmp;
            if(tmp)
            {
                if(big)
                {
                    peaks.insert(i);
                }
                big=false;
            }
            else
            {
                big=true;
            }
        }
        if(big)peaks.insert(n-1);

        minPQ<pair<int, pair<int, int>>> pq;
        for(auto iter=peaks.begin();next(iter)!=peaks.end();iter++)
            pq.push({(*next(iter)) - (*iter), {*iter, *next(iter)}});

        while(!pq.empty())
        {
            int left = pq.top().second.first;
            int right = pq.top().second.second;
            pq.pop();
            
            if (peaks.find(left) == peaks.end() || peaks.find(right) == peaks.end())
                continue;
            
            cout << "? " << left+1 << " " << right << endl;
            int lefty;
            cin>>lefty;
            cout << "? " << left+1 << " " << right+1 << endl;
            int all;
            cin>>all;
            if(all == lefty) // right most is biggest
            {
                peaks.erase(left);
                auto it = peaks.find(right);
                if(it!=peaks.begin())
                    pq.push({right - *prev(it), {*prev(it), right}});
            }
            else
            {
                peaks.erase(right);
                auto it = peaks.find(left);
                if(next(it)!=peaks.end())
                    pq.push({*next(it) - left, {left, *next(it)}});
            }
        }
        assert(peaks.size() == 1);
        
        cout << "! " << (*peaks.begin())+1 << endl;

    }
    return 0;
}