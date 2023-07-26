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

int getParent(int i, vector<int> &parent)
{
    if(parent[parent[i]]!=parent[i])
    {
        parent[i]=getParent(parent[i], parent);
    }return parent[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, m;
        cin>>n>>m;
        vector<int> heights(n);
        for(int i=0;i<n;i++)cin>>heights[i];
        vector<array<int,3>> edges(m);
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<3;j++)cin>>edges[i][j], edges[i][j]--;
            edges[i][0]=max(heights[edges[i][1]], heights[edges[i][2]]);
        }      
        sort(edges.begin(), edges.end());
        int edgePtr=0;
        int q;
        cin>>q;
        vector<array<int, 4>> queries(q);
        for(int i=0;i<q;i++)
        {
            for(int j=2;j>=0;j--)cin>>queries[i][j];
            queries[i][1]--, queries[i][2]--;
            queries[i][3]=i;
            queries[i][0]+=heights[queries[i][2]];
        }

        vector<int> parent(n), size(n, 1);
        for(int i=0;i<n;i++)parent[i]=i;
        vector<bool> ans(q, 0);
        sort(queries.begin(), queries.end());
        for(int i=0;i<q;i++)
        {
            while(edgePtr<m&&edges[edgePtr][0]<=queries[i][0])
            {
                int u=edges[edgePtr][1], v=edges[edgePtr][2];
                int p1=getParent(u, parent), p2=getParent(v, parent);
                if(size[p1]<size[p2])swap(u, v), swap(p1, p2);
                parent[p2]=p1;
                size[p1]+=size[p2];
                edgePtr++;
            }
            int u=queries[i][1], v=queries[i][2];
            if(getParent(u, parent)==getParent(v, parent))ans[queries[i][3]]=1;
        }
        for(int i=0;i<q;i++)
        {
            cout << (ans[i]?"YES":"NO") << '\n';
        }
    }
    return 0;
}