#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

bool hasCycle(vector<vector<int>> &al, vector<bool> &inPath, vector<bool> &done, int u)
{
    done[u]=true;
    inPath[u]=true;
    for(auto v:al[u])
    {
        if(inPath[v])return true;
        if(!done[v]&&hasCycle(al, inPath, done, v))return true;
    }
    inPath[u]=false;
    return false;
}

vector<int> path;

void topSort(vector<vector<int>> &al, vector<bool> &done, int u)
{
    done[u]=true;
    for(auto v:al[u])
    {
        if(!done[v])
        {
            topSort(al, done, v);
        }
    }
    path.push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> al(n);
        vector<array<int,2>> toAdd;
        for(int i=0;i<m;i++)
        {
            int t, u, v;
            cin>>t>>u>>v;
            --u,--v;
            if(t)
            {
                al[u].push_back(v);
            }
            else
            {
                toAdd.push_back({u, v});
            }
        }
        vector<bool> inPath(n, false);
        vector<bool> done(n, false);
        bool ok = true;
        for(int i=0;i<n&&ok;i++)
        {
            if(!done[i]&&hasCycle(al, inPath, done, i))
            {
                ok=false;
            }
        }
        if(!ok)
        {
            cout << "NO" << '\n';
            continue;
        }
        for(int i=0;i<n;i++)done[i]=false;
        path.clear();
        for(int i=0;i<n;i++)
            if(!done[i])
                topSort(al, done, i);
        reverse(path.begin(), path.end());
        vector<int> inds(n);
        for(int i=0;i<n;i++)
            inds[path[i]]=i;
        for(int i=0;i<toAdd.size();i++)
        {
            int u = toAdd[i][0], v = toAdd[i][1];
            if(inds[u]<inds[v])
            {
                al[u].push_back(v);
            }
            else
            {
                al[v].push_back(u);
            }
        }
        cout << "YES" << '\n';
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(al[i].size())
            {
                for(int j=0;j<al[i].size();j++)
                {
                    cout << i+1 << ' ' << al[i][j]+1 << '\n';
                } 
            }
        }
    }
    return 0;
}