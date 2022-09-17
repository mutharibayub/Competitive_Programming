#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adjList(n+1,vector<int>());
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    if(m-n!=1)
    {
        cout<<"NO\n";
        return 0;
    }
    vector<bool> done(n+1,false);
    queue<int> q;
    q.push(1);
    int visitCount = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        visitCount++;
        if(visitCount == n)
        if(done[node])
        {
            cout<<"NO\n";
            return 0;
        }
        done[node] = true;
        for(auto it:adjList[node])
        {
            if(it>=node)q.push(it);

        }
    }
    for(int i=1;i<done.size();i++)
    {
        if(!done[i])
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
}