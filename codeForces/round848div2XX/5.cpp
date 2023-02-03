#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

typedef long long ll;

class XorBase
{
    vector<ll> bases;
    int bitCount=0;
public:
    XorBase(){}
    XorBase(int bitCnt)
    {
        init(bitCnt);
    }
    void init(int bitCnt)
    {
        bases.assign(bitCnt, 0);
        bitCount=bitCnt;
    }
    void add(ll mask)
    {
        for(int bit=bitCount-1;bit>=0;bit--)
        {
            if(mask&(1<<bit))
            {
                if(bases[bit])
                {
                    mask^=bases[bit];
                }
                else
                {
                    bases[bit]=mask;
                    return;
                }
            }
        }
    }
    void merge(const XorBase &xb)
    {
        for(auto base:xb.bases)
        {
            if(base)add(base);
        }
    }
    ll getLargest()
    {
        ll out=0;
        for(int i=bitCount-1;i>=0;i--)
        {
            if(!(out&(1<<i)))out^=bases[i];
        }
        return out;
    }
};

const int BIT_COUNT = 31;
const int N = 2e5+1;
int parent[N];
int depth[N];
vector<int> al[N];
XorBase xb[N];
int val[N];

void dfs(int u)
{
    for(auto v:al[u])
    {
        if(parent[u]!=v)
        {
            parent[v]=u;
            depth[v]=depth[u]+1;
            dfs(v);
        }
    }
}

void eulerDfs(int u, vector<int> &tour)
{
    tour.push_back(u);
    for(auto v:al[u])
    {
        if(parent[u]!=v)
        {
            eulerDfs(v, tour);
            tour.push_back(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0;i<n;i++)al[i].clear();
        for(int i=0;i<n;i++)xb[i].init(BIT_COUNT);
        parent[0]=-1, depth[0]=0;

        for(int i=0;i<n;i++)
        {
            cin>>val[i];
            xb[i].add(val[i]);
        }

        for(int i=0;i<n-1;i++)
        {
            int u, v;
            cin>>u>>v;
            --u, --v;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        dfs(0);

        vector<array<int,2>> nodes(n);
        for(int i=0;i<n;i++)
        {
            nodes[i]={depth[i],i};
        }
        sort(nodes.rbegin(), nodes.rend());
        for(int i=0;i<n-1;i++)
        {
            int u = nodes[i][1];
            xb[parent[u]].merge(xb[u]);
        }

        vector<int> eulerTour;
        vector<vector<int>> d(n);
        eulerDfs(0, eulerTour);
        for(int i=0;i<eulerTour.size();i++)d[eulerTour[i]].push_back(i);
        vector<XorBase> pref(eulerTour.size()), suff(eulerTour.size());
        pref[0].init(BIT_COUNT);
        suff.back().init(BIT_COUNT);

        for(int i=0;i<eulerTour.size();i++)
        {
            if(i)pref[i]=pref[i-1];
            pref[i].add(val[eulerTour[i]]);
        }
        for(int i=eulerTour.size()-1;i>=0;i--)
        {
            if(i+1<eulerTour.size())suff[i]=suff[i+1];
            suff[i].add(val[eulerTour[i]]);
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int r, v;
            cin>>r>>v;
            --r,--v;
            if(v==r)
            {
                cout << pref.back().getLargest() << '\n';
            }
            else if(d[v].front()<d[r].front()&&d[v].back()>d[r].back()) // root is descendent of vertex
            {
                XorBase tmp(BIT_COUNT);
                int start = *(--lower_bound(d[v].begin(), d[v].end(), d[r].front()));
                int end = *lower_bound(d[v].begin(), d[v].end(), d[r].back());
                tmp.merge(pref[start]);
                tmp.merge(suff[end]);
                cout << tmp.getLargest() << '\n';
            }   
            else
            {
                cout << xb[v].getLargest() << '\n';
            }
        }

        vector<int> stk;
    }

    return 0;
}