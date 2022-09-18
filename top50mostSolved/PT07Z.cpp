#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <array>
#include <utility>

using namespace std;

void calcMaxLen(vector<list<array<int,2>>> &adjList, array<int,2> &node, int pNode)
{
    vector<pair<int, array<int,2>*>> stk;
    stk.push_back(make_pair(pNode,&node));
    while(!stk.empty())
    {
        pair<int,array<int,2>*> tmp = stk.back();
        int thisNode = tmp.second[0][0];
        int parentNode = tmp.first;
        int maxLen = 1;
        bool pushed = false;
        for(auto iter = adjList[thisNode].begin(); iter!=adjList[thisNode].end();iter++)
        {
            int neighNode = (*iter)[0];
            int &neighNodeMaxLen = (*iter)[1];
            if(neighNode!=parentNode)
            {
                if(neighNodeMaxLen==-1)
                {
                    stk.push_back(make_pair(thisNode, &(*iter)));
                    pushed = true;
                }
                else
                {
                    maxLen = max(maxLen, neighNodeMaxLen+1);
                }
            }
            
        }
        if(!pushed)
        {
            tmp.second[0][1] = maxLen;
            stk.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<list<array<int,2>>> adjList(n+1);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back({v,-1});
        adjList[v].push_back({u,-1});
    }
    int maxLen = -1;
    for(int i=1;i<=n;i++)
    {
        if(adjList[i].size()==1)continue;
        vector<int> maxLens;
        for(auto iter = adjList[i].begin(); iter!=adjList[i].end();iter++)
        {
            if((*iter)[1]==-1)
            {
                calcMaxLen(adjList, *iter, i);
            }
            maxLens.push_back((*iter)[1]);
        }
        sort(maxLens.rbegin(), maxLens.rend());
        maxLen = max(maxLen, maxLens[0]+maxLens[1]);
    }
    cout << maxLen <<'\n';
}