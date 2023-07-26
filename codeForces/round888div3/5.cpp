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

const int MOD = 1e9+7;

ll pwr(ll n, ll e)
{
    ll o=1;
    while(e)
    {
        if(e%2)o=o*n%MOD;
        e/=2;
        n=n*n%MOD;
    }return o;
}

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, k;
        cin>>n>>k;
        vector<ll> cost(n);
        for(int i=0;i<n;i++)cin>>cost[i];
        for(int i=0;i<k;i++)
        {
            int p;
            cin>>p;
            cost[--p]=0;
        }
        vector<vector<int>> influences(n);
        vector<int> influencedCount(n, 0);
        vector<vector<int>> madeFrom(n);
        for(int i=0;i<n;i++)
        {
            int m;
            cin>>m;
            influencedCount[i]=m;
            for(int j=0;j<m;j++)
            {
                int pp;
                cin>>pp;
                --pp;
                influences[pp].push_back(i);
                madeFrom[i].push_back(pp);
            }
        }
        vector<bool> done(n, false);
        int doneCount=0;
        minPQ<array<ll, 2>> pq;
        for(int i=0;i<n;i++)pq.push({cost[i], i});
        while(doneCount<n)
        {
            int potion = pq.top()[1];
            ll ccost = pq.top()[0];
            cost[potion]=ccost;
            done[potion]=true;
            doneCount++;
            for(auto ele:influences[potion])
            {
                if(!--influencedCount[ele])
                {
                    ll tmpCost=0;
                    for(auto ele1:madeFrom[ele])
                    {
                        tmpCost+=cost[ele1];
                    }
                    pq.push({tmpCost, ele});
                }
            }
            while(pq.size()&&done[pq.top()[1]])pq.pop();
        }
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << cost[i];
        }cout << '\n';
    }
    return 0;
}