#include <iostream>
#include <vector>
#include <unordered_set>
#include <array>
#include <algorithm>

using namespace std;

int LCA(vector<vector<int>> &up, vector<int> &depth, int v, int w)
{
    if(depth[v]<depth[w])swap(v,w);
    int k = up[0].size();
    for(int jump=k-1;jump>=0&&depth[v]>depth[w];jump--)
    {
        while(depth[v]-(1<<jump)>=depth[w])v=up[v][jump];
    }
    if(v==w)return v;
    for(int jump=k-1;jump>=0;jump--)
    {
        while(up[v][jump]!=up[w][jump])
        {
            v=up[v][jump];
            w=up[w][jump];
        }
    }
    return up[v][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int k=0;
    while((1<<k)<n)k++;
    vector<vector<int>> adjList(n);
    vector<vector<int>> up(n,vector<int>(k,-1));
    vector<int> depth(n,0);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vector<int> stk;
    stk.push_back(0);
    while(stk.size())
    {
        int top = stk.back();
        stk.pop_back();
        for(auto adj:adjList[top])
        {
            if(adj!=up[top][0])
            {
                stk.push_back(adj);
                up[adj][0]=top;
                depth[adj]=depth[top]+1;
            }
        }
    }

    for(int i=1;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(up[j][i-1]!=-1)
            {
                up[j][i]=up[up[j][i-1]][i-1];
            }
        }
    }

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int c;
        cin>>c;
        vector<bool> done(c, false);
        vector<array<int,2>> nodes(c);
        for(int j=0;j<c;j++)
        {
            cin>>nodes[j][1];
            nodes[j][1]--;
            nodes[j][0]=depth[nodes[j][1]];
        }
        sort(nodes.rbegin(), nodes.rend());
        int sDeep=-1;
        for(int j=1;j<c;j++)
        {
            if(LCA(up, depth, nodes[0][1], nodes[j][1])==nodes[j][1])done[j]=true;
            else if(sDeep==-1)sDeep=j;
        }
        if(sDeep==-1)
        {
            cout << "YES\n";
            continue;
        }
        int left=-1;
        for(int j=sDeep+1;j<c;j++)
        {
            if(done[j])continue;
            if(LCA(up, depth, nodes[sDeep][1], nodes[j][1])==nodes[j][1])done[j]=true;
            else if(left==-1)left=j;
        }
        if(left==-1 && depth[nodes.back()[1]]>=depth[LCA(up, depth, nodes[0][1], nodes[sDeep][1])])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

}