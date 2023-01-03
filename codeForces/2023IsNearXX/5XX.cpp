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

void dfs(vector<vector<int>> &al, vector<int> &parent, vector<int> &depth, int node)
{
    for(int i=0;i<al[node].size();i++)
    {
        if(al[node][i]!=parent[node])
        {
            parent[al[node][i]]=node;
            depth[al[node][i]]=depth[node]+1;
            dfs(al,parent,depth,al[node][i]);
        }
    }
}

void calcAns(vector<vector<int>> &al, vector<int> &parent, vector<ll> &stp, vector<ll> &sta, vector<ll> &prob, vector<ll> &ans, int node, ll cprob, ll cans)
{
    ans[node]=norm(cans+sta[node]);
    ll upAns = norm(cans+cprob+prob[node]);
    ll upProb = norm(cprob+prob[node]);
    ll armsProb = norm(stp[node]-prob[node]);
    ll armsAns = norm(sta[node]+armsProb);
    for(int i=0;i<al[node].size();i++)
    {
        int child = al[node][i];
        if(parent[node]!=child)
        {
            ll armProb = stp[child];
            ll armAns = norm(sta[child]+2*armProb);
            cprob = norm(upProb+armsProb-armProb);
            cans = norm(upAns+armsAns-armAns);
            calcAns(al,parent,stp,sta,prob,ans,child,cprob,cans);
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
    vector<int> depth(n,0);
    ll inv2 = power(2,MOD-2);
    for(int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        a--;
        prob[a]=1;
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        al[a].push_back(b);
        al[b].push_back(a);
        ll newB=prob[b],newA=prob[a];
        if(prob[a]&&prob[b]!=1)
        {
            newB=norm(newB+(norm(norm(1-prob[b])*inv2)*prob[a]));
        }
        else if(prob[b]&&prob[a]!=1)
        {
            newA=norm(newA+(norm(norm(1-prob[a])*inv2)*prob[b]));
        }
        prob[a]=newA;
        prob[b]=newB;
    }
    dfs(al,parent,depth,0);
    vector<pair<int,int>> ord(n);
    vector<ll> subTreeProb=prob; 
    vector<ll> subTreeAns(n,0);
    vector<ll> ans(n,0);
    for(int i=0;i<n;i++)ord[i]={depth[i],i};
    sort(ord.rbegin(),ord.rend());
    for(int i=0;i<n;i++)
    {
        int node=ord[i].second;
        if(parent[node]!=-1)
        {
            subTreeProb[parent[node]]=norm(subTreeProb[parent[node]]+subTreeProb[node]);
            subTreeAns[parent[node]]=norm(subTreeAns[parent[node]]+subTreeAns[node]+subTreeProb[node]);
        }
    }
    ll fAns = 0;
    calcAns(al,parent,subTreeProb,subTreeAns,prob,ans,0,0,0);
    ll count=0;
    for(int i=0;i<n;i++)
    {
        if(prob[i])
        {
            fAns = norm(fAns+ans[i]);
            count++;
        }
    }
    fAns=norm(fAns*power(count,MOD-2));
    cout << fAns << '\n';
    

    return 0;
}