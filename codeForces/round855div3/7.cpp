#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const int N = 2e5+1;
int parent[N];
int depth[N];
vector<int> al[N];

void dfs(int root)
{
    for(auto u:al[root])
    {
        if(parent[root]!=u)
        {
            parent[u]=root;
            depth[u]=depth[root]+1;
            dfs(u);
        }
    }
}
 
bool checkSymmetry(vector<int> &arr, set<int> &sym)
{
    map<int,int> counts;
    for(int i=0;i<arr.size();i++)
    {
        counts[arr[i]]++;
    }
    int cnt = 0;
    int symc = -1;
    for(auto val:counts)
    {
        if(val.second%2)
        {
            cnt++;
            symc=val.first;
        }
    }
    return cnt==0||(cnt==1&&(sym.find(symc)!=sym.end()));
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
        vector<int> cls(n, 0);
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            --u,--v;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        depth[0]=0;
        parent[0]=-1;
        dfs(0);
        vector<pair<int,int>> srt(n);
        for(int i=0;i<n;i++)srt[i]={depth[i], i};
        sort(srt.rbegin(), srt.rend());
        vector<bool> symmetrical(n, true);
        vector<vector<int>> tt(n);
        vector<set<int>> sym(n);
        for(int i=0;i<n;i++)
        {
            if(i&&srt[i-1].first>srt[i].first)
            {
                int r = i;
                while(r<n-1&&srt[r+1].first==srt[r].first)r++;
                vector<pair<vector<int>,int>> tmp;
                for(int j=i;j<=r;j++)
                {
                    sort(tt[srt[j].second].begin(), tt[srt[j].second].end());
                    symmetrical[srt[j].second]=checkSymmetry(tt[srt[j].second], sym[srt[j].second]);
                }
                for(int j=i;j<=r;j++)tmp.push_back({tt[srt[j].second],srt[j].second});
                sort(tmp.begin(), tmp.end());
                int cnt = 1;
                cls[tmp.front().second]=0;
                for(int j=0;j+1<tmp.size();j++)
                {
                    if(tmp[j].first!=tmp[j+1].first)
                    {
                        cnt++;
                    }
                    cls[tmp[j+1].second]=cnt-1;
                }
            }
            if(i+1<n)
            {
                tt[parent[srt[i].second]].push_back(cls[srt[i].second]);
                if(symmetrical[srt[i].second])sym[parent[srt[i].second]].insert(cls[srt[i].second]);
            }
        }
        cout << (symmetrical[0]?"YES":"NO") << '\n';
    }

    return 0;
}