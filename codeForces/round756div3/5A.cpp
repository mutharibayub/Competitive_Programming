#include <iostream>
#include <vector> 
#include <array>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &al, vector<int> &parent, vector<int> &depth, int root)
{
    for(auto child:al[root])
    {
        if(parent[root]==child)continue;
        depth[child]=depth[root]+1;
        parent[child]=root;
        dfs(al,parent,depth,child);
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
        int n,k;
        cin>>n>>k;
        vector<int> friends(k);
        vector<int> parent(n,-1);
        vector<int> depth(n,-1);
        vector<vector<int>> al(n);
        for(int i=0;i<k;i++)
        {
            cin>>friends[i];
            --friends[i];
        }
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            al[--a].push_back(--b);
            al[b].push_back(a);
        }
        depth[0]=0;
        dfs(al,parent,depth,0);
        vector<int> no(n,-1);
        for(int i=0;i<k;i++)
        {
            int halfDepth = depth[friends[i]]/2;
            int node=friends[i];
            no[node]=halfDepth;
        }
        vector<array<int,2>> nodes(n);
        for(int i=0;i<n;i++)
        {
            nodes[i][0]=depth[i];
            nodes[i][1]=i;
        }
        sort(nodes.rbegin(),nodes.rend());
        for(int i=0;i<n;i++)
        {
            int node=nodes[i][1];
            if(parent[node]==-1||no[node]==-1)continue;
            no[parent[node]]=max(no[parent[node]],no[node]-1);
        }
        vector<int> stk;
        stk.push_back(0);
        bool ok=false;
        while(!stk.empty())
        {
            int top = stk.back();
            stk.pop_back();
            if(no[top]>=0)continue;
            if(al[top].size()==1&&top!=0)
            {
                ok=true;
                break;
            }
            for(auto child:al[top])
            {
                if(parent[top]==child)continue;
                stk.push_back(child);
            }
        }
        cout << (ok?"YES":"NO") << '\n';

    }
}