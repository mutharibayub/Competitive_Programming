#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

ll MOD = 998244353;

ll norm(ll n)
{
    return (n%MOD+MOD)%MOD;
}

ll power(ll n, ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
        {
            ans=norm(ans*n);
        }
        n=norm(n*n);
        e/=2;
    }
    return ans;
}

void dfs(vector<vector<int>> &al, vector<ll> &prob, vector<int> &parent, vector<ll> &size, int node)
{
    if(prob[node])size[node]=1;
    for(int i=0;i<al[node].size();i++)
    {
        if(al[node][i]!=parent[node])
        {
            parent[al[node][i]]=node;
            dfs(al,prob,parent,size,al[node][i]);
            size[node]+=size[al[node][i]];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    vector<ll> prob(n,0);
    vector<vector<int>> al(n);
    vector<int> parent(n,-1);
    vector<ll> size(n,0);
    vector<pair<int,int>> edges;
    ll inv2 = power(2,MOD-2);
    for(int i=0;i<k;i++)
    {
        int b;
        cin>>b;
        b--;
        prob[b]=1;
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        al[a].push_back(b);
        al[b].push_back(a);
        edges.emplace_back(a,b);
    }
    dfs(al,prob,parent,size,0);
    ll ans=0;
    for(int i=0;i<n-1;i++)
    {
        int a = edges[i].first, b = edges[i].second;
        if(parent[a]==b)swap(a,b);
        ll pAB=norm(prob[a]*(1-prob[b])),pBA=norm(prob[b]*(1-prob[a]));
        ll aToB=norm(size[b]*(k-size[b]))-norm(size[b]*(k-size[b])%MOD*pAB)+norm((size[b]+1)*(k-size[b]-1)%MOD*pAB);
        ll bToA=norm(size[b]*(k-size[b]))-norm(size[b]*(k-size[b])%MOD*pBA)+norm((size[b]-1)*(k-size[b]+1)%MOD*pBA);
        ans = ans+norm(norm(aToB+bToA)*inv2);
        ans = norm(ans);
        prob[a]=prob[b]=norm((prob[a]+prob[b])*inv2);
    }
    cout << norm(ans*power(norm(1ll*k*(k-1)/2), MOD-2)) << '\n';
    return 0;
}