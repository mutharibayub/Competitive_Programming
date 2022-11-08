#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>

using namespace std;

#define ll long long

int getParent(vector<int> &parent, int v)
{
    vector<int> stk;
    while(parent[v]!=v)
    {
        stk.push_back(v);
        v=parent[v];
    }
    while(!stk.empty())
    {
        parent[stk.back()] = parent[v];
        stk.pop_back();
    }
    return v;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adjList(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vector<int> parent(n);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        int parent1=getParent(parent, i);
        for(int j=0;j<adjList[i].size();j++)
        {
            int parent2=getParent(parent, adjList[i][j]);
            if(parent1<parent2)
            {
                parent[parent2]=parent1;
            }
            else
            {
                parent[parent1]=parent2;
            }
        }
    }
    unordered_map<int, vector<int>> sets;
    for(int i=0;i<n;i++)
    {
        sets[getParent(parent, i)].push_back(i);
    }
    int count = 0;
    for(auto &set:sets)
    {
        bool found = true;
        for(int i=0;i<set.second.size();i++)
        {
            if(adjList[set.second[i]].size()!=2)
            {
                found=false;
                break;
            }
        }
        if(found)count++;
    }
    cout << count << '\n';

    return 0;
}