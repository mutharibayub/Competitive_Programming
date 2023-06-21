#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
 
void dfs(int mx, int mn, int cmx, int cmn, int u, vector<vector<int>> &children, vector<vector<pair<int,int>>> &query, vector<int> &ans, vector<int> &weight)
{
    for(int i=0;i<query[u].size();i++) 
    {
        if(mn<=query[u][i].second && mx>=query[u][i].second)
        {
            ans[query[u][i].first]=1;
        }
    }
    for(int i=0;i<children[u].size();i++)
    {
        int nw = weight[children[u][i]];
        int tcmx = max(cmx+nw, nw);
        int tcmn = min(cmn+nw, nw);
        int tmx = max(mx, tcmx);
        int tmn = min(mn, tcmn);
        dfs(tmx, tmn, tcmx, tcmn, children[u][i], children, query, ans, weight);
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
        int e;
        cin>>e;
        int n=1;
        int q=0;
        vector<vector<int>> children(n);
        vector<vector<pair<int,int>>> query(n);
        vector<int> weight(n,1);
        vector<int> ans; 
        for(int i=0;i<e;i++) 
        {
            string tp;
            cin>>tp;
            if(tp=="+")
            {
                int v, x;
                cin>>v>>x;
                --v;
                children.push_back({});
                children[v].push_back(n);
                weight.push_back(x);
                query.push_back({});
                n++;
            }
            else
            {
                int u, v, k;
                cin>>u>>v>>k;
                --u,--v;
                ans.push_back(0);
                query[v].push_back({q, k});
                q++;
            }
        }
        dfs(1, 0 , 1, 0, 0, children, query, ans, weight);
        for(int i=0;i<q;i++) 
        {
            cout << (ans[i]?"YES":"NO") << '\n';
        }
    }
 
    return 0;
}