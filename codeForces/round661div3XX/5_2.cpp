#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

void dfs(vector<vector<array<int,3>>> &al, vector<array<int,3>> &parent, vector<int> &cnt, vector<ll> &weight, int u, ll sum)
{
    for(auto pr:al[u])
    {
        int v = pr[0];
        int w = pr[1];
        if(parent[u][0]==v)continue;
        parent[v]={u, w, pr[2]};
        dfs(al, parent, cnt, weight, v, sum+w);
        cnt[u]+=cnt[v];
    }
    if(al[u].size()==1&&u!=0)
    {
        weight[u] = sum;
        cnt[u]=1;
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
        ll s;
        cin>>n>>s;
        vector<vector<array<int,3>>> al(n);
        for(int i=0;i<n-1;i++)    
        {
            int u, v, w, c;
            cin>>u>>v>>w>>c;
            --u,--v;
            al[u].push_back({v, w, c});
            al[v].push_back({u, w, c});
        }
        vector<int> cnt(n, 0);
        vector<array<int,3>> parent(n);
        vector<ll> weight(n, -1);
        parent[0]={-1, 0, 0};
        dfs(al, parent, cnt, weight, 0, 0);
        ll totalSum = 0;
        for(int i=0;i<n;i++)
        {
            if(weight[i]!=-1)totalSum+=weight[i];
        }
        vector<ll> pf1;
        vector<ll> pf2;
        for(int i=1;i<n;i++)
        {
            auto &arr=(parent[i][2]==1)?pf1:pf2;
            while(parent[i][1])
            {
                arr.push_back(1ll*cnt[i]*((parent[i][1]+1)/2));
                parent[i][1]/=2;
            }
        }
        sort(pf1.rbegin(), pf1.rend());
        sort(pf2.rbegin(), pf2.rend());
        for(int i=1;i<pf1.size();i++)pf1[i]+=pf1[i-1];
        for(int i=1;i<pf2.size();i++)pf2[i]+=pf2[i-1];
        int ans = 1e9+7;
        ll target = totalSum-s;
        int ind = lower_bound(pf1.begin(), pf1.end(), target)-pf1.begin();
        if(target<=0)ans=0;
        else if(ind<pf1.size()&&pf1[ind]>=target)ans=ind+1;
        for(int i=0;i<pf2.size();i++)
        {
            if(pf2[i]>=target)ans=min(ans, 2*(i+1));
            else 
            {
                ind = lower_bound(pf1.begin(), pf1.end(), target-pf2[i])-pf1.begin();
                if(ind<pf1.size()&&pf1[ind]>=target-pf2[i])ans=min(ans, (i+1)*2+ind+1);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}