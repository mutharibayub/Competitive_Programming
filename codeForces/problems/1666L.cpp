#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    int v,e,sVert;
    cin>>v>>e>>sVert;
    vector<list<int>> adjList(v+1);
    for(int i=0;i<e;i++)
    {
        int num1,num2;
        cin>>num1>>num2;
        adjList[num1].push_back(num2);
    }

    if(adjList[sVert].size()<=1)
    {
        cout<<"Impossible\n";
        return 0;
    }

    vector<int> gtree(v+1,-1);
    unordered_map<int,int> ttree;
    int cross_node=-1;
    for(auto sNode:adjList[sVert])
    {
        ttree.clear();
        queue<int> q;
        if(gtree[sNode]!=-1)
        {
            cross_node=sNode;
        }
        q.push(sNode);
        // cout<<"Snode: "<<sNode<<endl;
        ttree[sNode]=sVert;
        ttree[sVert]=-1;
        while(!q.empty() && cross_node==-1)
        {
            int node=q.front();
            q.pop();
            for(auto neighbour:adjList[node])
            {
                // cout<<neighbour<<" ";
                if(gtree[neighbour]!=-1)
                {
                    cross_node=neighbour;
                    ttree[neighbour]=node;
                    break;
                }
                else if(ttree.find(neighbour)==ttree.end())
                {
                    ttree[neighbour]=node;
                    q.push(neighbour);
                }
            }
        }
        // cout<<"YES\n";
        if(cross_node!=-1)break;
        for(auto it:ttree)
        {
            // cout<<it.first<<" "<<it.second<<"\n";
            gtree[it.first]=it.second;
        }
    }
    if(cross_node==-1)
    {
        cout<<"Impossible\n";
        return 0;
    }
    
    vector<vector<int>> paths(2);
    for(int i=0;i<2;i++)
    {
        int ptr=cross_node;
        while(ptr!=-1)
        {
            paths[i].push_back(ptr);
            if(!i)
            {
                ptr=gtree[ptr];
            }
            else
            {
                ptr=ttree[ptr];
            }
        }
    }
    cout<<"Possible\n";
    for(int i=0;i<2;i++)
    {
        reverse(paths[i].begin(),paths[i].end());   
        cout<<paths[i].size()<<"\n";
        for(int j=0;j<paths[i].size();j++)
        {
            if(j)cout<<" ";
            cout<<paths[i][j];
        }cout<<"\n";
    }
    return 0;
}