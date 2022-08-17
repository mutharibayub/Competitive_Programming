#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <array>
#include <queue>

using namespace std;

int getMaxDist(const vector<list<int>>& adjList, int start)
{
    int n = adjList.size();
    vector<bool> visited(n+1,false);
    visited[start]=true;
    queue<array<int,2>> q;
    q.push({start,0});
    int maxLen = -1;
    while(!q.empty())
    {
        array<int,2> tmp = q.front();
        maxLen = max(maxLen, tmp[1]);
        q.pop();
        for(auto it:adjList[tmp[0]])
        {
            if(!visited[it])
            {
                q.push({it, tmp[1]+1});
                visited[it]=true;
            }
        }
    }
    return maxLen;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<list<int>> adjList(n+1);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int maxLen = -1;
    for(int i=1;i<=n;i++)
    {
        if(adjList[i].size()==1)
        {
            maxLen = max(maxLen, getMaxDist(adjList, i));
        }
    }
    cout << maxLen <<'\n';
}