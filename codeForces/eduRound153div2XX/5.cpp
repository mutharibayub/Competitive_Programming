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

    int tttt=1;
    // cin>>tttt;
    while(tttt--)
    {
        function<int(char, char)> enc = [](char c1, char c0) {return (c1-'a')*26 + c0-'a';};

        string s;
        cin>>s;
        int n=s.size()-1;
        vector<vector<pair<int, int>>> al(n+26*26);

        for(int i=0;i<n;i++)
        {
            if(i<n-1)
            {
                al[i].push_back({i+1, 1});
                al[i+1].push_back({i, 1});
            }
            al[n+enc(s[i], s[i+1])].push_back({i, 0});
            al[i].push_back({n+enc(s[i], s[i+1]), 1});
        }

        int qq;
        cin>>qq;
        vector<pair<int,int>> queries(qq);
        vector<int> ans(qq);
        for(int i=0;i<qq;i++)
        {
            cin>>queries[i].first>>queries[i].second;
            queries[i].first--, queries[i].second--;
            ans[i]=abs(queries[i].first-queries[i].second);
        }

        for(int i=0;i<26*26;i++)
        {
            vector<int> dist(n+26*26, 1e9);
            vector<bool> done(n+26*26, 0);
            deque<int> q;
            q.push_back(n+i);
            dist[n+i]=0;
            while(!q.empty())
            {
                int u = q.front();
                done[u]=true;
                q.pop_front();
                for(auto [v, w]: al[u])
                {
                    if(dist[u]+w<dist[v])
                    {
                        if(w)q.push_back(v);
                        else q.push_front(v);
                        dist[v]=dist[u]+w;
                    }
                }
                while(!q.empty()&&done[q.front()])q.pop_front();
            }
            for(int j=0;j<qq;j++)
            {
                ans[j]=min(ans[j], dist[queries[j].first]+dist[queries[j].second]+1);
            }
        }
        for(int i=0;i<qq;i++)
        {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}